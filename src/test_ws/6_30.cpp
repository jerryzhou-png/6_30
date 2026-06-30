#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc,char **argv){
  ros::init(argc,argv);
  ros::NodeHandle nh;
  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 10);
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok()){
    // 建立一個標準的 ROS 字串訊息物件
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str(); // 將內容填入訊息的 data 欄位
    ROS_INFO("%s", msg.data.c_str());
    //  訊息發布出去
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
        ++count;
    }
    return 0;
}
