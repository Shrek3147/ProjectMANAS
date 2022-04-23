#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int8.h>


#include <sstream>

using namespace std;


string encrypt(string text, int s)
{
	//string result = "";
	string result1 = "";

	// traverse text
	for (int i=0;i<text.length();i++)
	{
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(text[i]))
			result1 += char(int(text[i]+s-65)%26 +65);

	// Encrypt Lowercase letters
	else{
		result1 += char(int(text[i]+s-97)%26 +97);
		//result1 += char(int(result[i]+(26-s)-97)%26 +97);
	}
	}

	// Return the resulting string
	return result1;
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "talker");

  
  ros::NodeHandle n;

  
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

  
  int count = 0;
  while (ros::ok())
  {
    std_msgs::Int8 msg1;
    msg1.data = 5;
    
    std_msgs::String msg;
    string text="manas taskphase";
    int s=3;
    std::string colour[4] = { "Blue", "Red", "Orange", "Yellow" };

   
    for (int i = 0; i < 4; i++)
    {
    string text1 = encrypt(colour[i], s);
    msg.data = text1;
    //ROS_INFO("%d", msg1.data);
    //chatter_pub.publish(msg1);

    ROS_INFO("encrypted message: [%s]", msg.data.c_str());

    
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
    }
  }


  return 0;
}