#include <ros/ros.h>

#include <std_msgs/String.h> 

#include <interactive_rmpc/RobotState.h>
#include <interactive_rmpc/PedestrianState.h>
#include <interactive_rmpc/MPCStates.h>


class SoundMaker
{
public:
    SoundMaker();
    ~SoundMaker();

private:
    ros::NodeHandle _nh;
    ros::NodeHandle _pnh;
    ros::Subscriber _judgment_sub;

    void ehmi_judgment_callback(const std_msgs::String::ConstPtr& msg);
    void add_information_contents(const std_msgs::String& judgment, std::string& information_contents);
};
