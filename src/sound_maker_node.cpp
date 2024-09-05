#include "sound/sound_maker.hpp"


int main(int argc,char **argv)
{
    ros::init(argc, argv, "sound_maker");
    SoundMaker sm;
    ros::spin();

    return 0;
}
