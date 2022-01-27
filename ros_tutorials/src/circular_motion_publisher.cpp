#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
/* Your code here*/
#include <ros_tutorials/RV.h>
/* Your code here*/


class CircularMotionPublisher
{
public:
    
    CircularMotionPublisher():loop_rate(10) //loop_rate 10Hz로 설정 
    {
        /*     Your code here       */
	pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
	sub = nh.subscribe("/circular_motion", 10, &CircularMotionPublisher::msgCallback, this);
        /*     Your code here       */ 
    }

    /*     Your code here       */ 
    void msgCallback(const ros_tutorials::RV::ConstPtr& msg)
    {
	//geometry_msgs::Twist twist;
	
        twist.linear.x = msg->velocity;
        twist.linear.y = 0;
        twist.linear.z = 0;

	float rad = msg->radius;
	
        twist.angular.x = 0;
        twist.angular.y = 0;
        twist.angular.z = (twist.linear.x / rad);

	//pub.publish(twist);
    }
    /*     Your code here       */ 
    

    // loop_rate에 맞게 저장된 Twist 메시지를 Publish하도록 spin 설정 
    void spin()
    {
        while(ros::ok())
        {
            pub.publish(twist);
            ros::spinOnce();
            loop_rate.sleep();
        }
    }

private:
    //nodehandle과 Publisher, Subscriber, 속도 정보를 저장할 Twist 메시지 객체 생성 
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Subscriber sub;
    ros::Rate loop_rate;
    geometry_msgs::Twist twist;
};


int main(int argc, char **argv)
{
    //ROS 시작 후 객체 생성 및 spin
    ros::init(argc, argv, "circular_motion_publisher");
    CircularMotionPublisher circular_motion_publisher;
    circular_motion_publisher.spin();
    return 0;
}
