#include <gazebo/common/Plugin.hh> 
#include "std_msgs/Int32.h"
#include <ros/ros.h>

namespace gazebo{

class WorldPluginTutorial : public WorldPlugin
{
private:
  void testCallback(const std_msgs::Int32::ConstPtr & msg)
  {
        ROS_INFO("Contador from plugin: %d", msg->data);
  }
public:
  WorldPluginTutorial() : WorldPlugin()
  {
  }

  void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
  {
    // Make sure the ROS node for Gazebo has already been initialized
    if (!ros::isInitialized())
    {
      ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
        << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
      return;
    }

    ROS_INFO("Plugin initilized!");
  }

};

GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)

}
