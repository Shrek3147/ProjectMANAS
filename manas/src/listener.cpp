#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

using namespace std;

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
string decrypt(string text, int s)
{
	//string result = "";
	string result1 = "";

	// traverse text
	for (int i=0;i<text.length();i++)
	{
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(text[i]))
			
      result1 += char(int(text[i]+(26-s)-65)%26 +65);

	// Encrypt Lowercase letters
	else{
		
		result1 += char(int(text[i]+(26-s)-97)%26 +97);
	}
	}

	// Return the resulting string
	return result1;
}
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  int s =3;
  string text = msg->data;
  string b = decrypt(text,s);
  //msg->data = b;
  ROS_INFO("Decrypted message: [%s]", b.c_str());
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "listener");

  
  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  
  ros::spin();

  return 0;
}
