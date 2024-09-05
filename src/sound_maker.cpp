#include "sound/sound_maker.hpp"

#include <ros/ros.h>
#include <std_msgs/String.h>

#include <interactive_rmpc/RobotState.h>
#include <interactive_rmpc/PedestrianState.h>
#include <interactive_rmpc/MPCStates.h>

SoundMaker::SoundMaker(): _nh(""), _pnh("")
{
    std::string ehmi_judgment_in_topic;
    _pnh.param<std::string>("ehmi_judgment_in",ehmi_judgment_in_topic,"/eHMI/judgment");

    _judgment_sub = _nh.subscribe(ehmi_judgment_in_topic, 1, &SoundMaker::ehmi_judgment_callback, this);
}

SoundMaker::~SoundMaker(){}

void SoundMaker::add_information_contents(const std_msgs::String& judgment, std::string& information_contents)
{
    //パラメータ（音声内容）
    std::string robot_first, pedestrian_first;
    _pnh.param<std::string>("robot_first_sound",robot_first,"Robot will go first.");
    _pnh.param<std::string>("pedestrian_first_sound",pedestrian_first,"Pedestrian will go first.");

    if (judgment.data == "Robot will go first.")
    {
        information_contents = robot_first;
    }
    else if (judgment.data == "Pedestrian will go first.")
    {
        information_contents = pedestrian_first;
    }
    else
    {
        information_contents = "No judgment";
    }
}

void SoundMaker::ehmi_judgment_callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I received Judgment : %s", msg->data.c_str());

    //パラメータ（スピーカーのデバイス名）
    std::string speaker_device_name;
    _pnh.param<std::string>("speaker_device_name",speaker_device_name,"alsa_output.pci-0000_00_1f.3.analog-stereo");

    //音声再生コマンド
    std::string information_contents;
    add_information_contents(*msg, information_contents);
    std::string command = "espeak -v en -s 150 -p 50 -a 200 --stdout \"" + information_contents + "\" | paplay --device=" + speaker_device_name;
    
    //デバッグ用
    int result = system(command.c_str());
    if (result != 0)
    {
        ROS_INFO("Failed to play sound");
    }
}
