#include <ros/ros.h>
#include <std_msgs/String.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <map>
#include <fstream>

struct Point{
    double x; 
    double y; 
    double z;
};

std::map<std::string, Point> artwork_database;

bool moveTo(double x, double y);

void speechCallback(const /* ... */& msg){
    auto item = artwork_database./* ... */(msg.data);
    if (/* ... */ != artwork_database.end()){
        ROS_INFO("Moving to %s. Please follow me!", msg./* ... */.c_str());
        moveTo(item->second.x, item->second.y);
    }
    else{
        ROS_ERROR("Target artwork not found in the database. Item was %s", msg.data.c_str());
    }
}


bool moveTo(double x, double y){
    
    actionlib::/* ... */<move_base_msgs::MoveBaseAction>  ac("move_base", true);
    //wait for the action server to come up
    while( !ac./* ... */(ros::Duration(5.0)) ){
        ROS_INFO("Waiting for the move_base action server to come up");
    }
    move_base_msgs::MoveBaseGoal /* ... */;
  
    goal.target_pose.header.frame_id = /* ... */;
    goal.target_pose.header.stamp = ros::Time::now();

    goal.target_pose.pose.position.x = /* ... */;
    goal.target_pose.pose.position.y = /* ... */;
    goal.target_pose.pose.position.z = 0.0;
    goal.target_pose.pose.orientation.x = 0.0;
    goal.target_pose.pose.orientation.y = 0.0;
    goal.target_pose.pose.orientation.z = 0.0;
    goal.target_pose.pose.orientation.w = /* ... */;

    ROS_INFO("Sending goal %2.2f %2.2f", goal.target_pose.pose.position.x, goal.target_pose.pose.position.y);
    
    ac./* ... */(/* ... */);

    //ac.waitForResult();
    bool result = ac.waitForResult(/* ... */);
    //if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    if (result)
        ROS_INFO("We are there.");
    else
        ROS_INFO("Error reaching destination!");
    return false;
}

int main(int argc, char **argv){
	ros::init(argc, argv, /* ... */);
	ros::NodeHandle nh;

    ros::Subscriber subs_barcode = nh.subscribe(/* ... */);

    std::ifstream file_artworkdb(/* ... */, std::ifstream::in);
    if (!/* ... */()){
        ROS_ERROR("Could not open artwork database!");
        return -1;
    }
    
    std::string label;
    Point pt;
    std::string line;
    while (std::getline(file_artworkdb, line)){
        
        char* pch;
        char buf[120];
        memcpy(buf, line.c_str(), line.size());
        pch = /* ... */(buf, ",");
        label = std::string(pch);
        
        pch = /* ... */(NULL, ",");
        pt.x = /* ... */(pch);
        pch = /* ... */(NULL, ",");
        pt.y = /* ... */(pch);
        pch = strtok(NULL, ",");
        pt.z = atof(pch);
        
        artwork_database./* ... */(/* ... */, /* ... */);
    }
    file_artworkdb./* ... */();

    std::cout << "Current Artwork in the Database: (" << /* ... */ << ")" << std::endl;
    for(auto artwork : artwork_database){
        std::cout << artwork./* ... */ << "\t" << artwork./* ... */ << "\t" << artwork./* ... */ << "\t" << artwork.second.z << std::endl;
    }
    
	ros::Rate rate(/* ... */);
	while(/* ... */){
		/* ... */;
		/* ... */;
	}
	
}
