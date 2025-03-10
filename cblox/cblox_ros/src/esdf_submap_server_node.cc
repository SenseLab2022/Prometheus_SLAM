#include <cblox_ros/submap_server.h>
#include <glog/logging.h>
#include <ros/ros.h>
#include <gflags/gflags.h>
int main(int argc, char** argv) {
  ros::init(argc, argv, "cblox");
  google::InitGoogleLogging(argv[0]);
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InstallFailureSignalHandler();
  ros::NodeHandle nh;
  ros::NodeHandle nh_private("~");

  cblox::SubmapServer<cblox::TsdfEsdfSubmap> node(nh, nh_private);

  ros::MultiThreadedSpinner spinner;
  spinner.spin();
  return 0;
}
