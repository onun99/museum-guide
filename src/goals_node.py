#!/usr/bin/env python
# license removed for brevity

import rospy

# Brings in the SimpleActionClient
import actionlib
# Brings in the .action file and messages used by the move base action
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from std_msgs.msg import String





def create_GoalPoints():
    goalAi = MoveBaseGoal()
    goalAi.target_pose.header.frame_id = "map"
    goalAi.target_pose.pose.position.x = 1
    goalAi.target_pose.pose.position.y = 1
    goalAi.target_pose.pose.orientation.w = 1.0

    goalBi = MoveBaseGoal()
    goalBi.target_pose.header.frame_id = "map"
    goalBi.target_pose.pose.position.x = 1.6
    goalBi.target_pose.pose.position.y = 6.7
    goalBi.target_pose.pose.orientation.w = 1.0

    goalCi = MoveBaseGoal()
    goalCi = MoveBaseGoal()
    goalCi.target_pose.header.frame_id = "map"
    goalCi.target_pose.pose.position.x = 6
    goalCi.target_pose.pose.position.y = 4.7
    goalCi.target_pose.pose.orientation.w = 1.0

    goalDi = MoveBaseGoal()
    goalDi = MoveBaseGoal()
    goalDi.target_pose.header.frame_id = "map"
    goalDi.target_pose.pose.position.x = 8.5
    goalDi.target_pose.pose.position.y = 6.9
    goalDi.target_pose.pose.orientation.w = 1.0

    return goalAi, goalBi, goalCi, goalDi

def movebase_client(goal):

   # Create an action client called "move_base" with action definition file "MoveBaseAction"
    client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
 
   # Waits until the action server has started up and started listening for goals.
    client.wait_for_server()

   # Creates a new goal with the MoveBaseGoal constructor
    goal.target_pose.header.stamp = rospy.Time.now()

   # Sends the goal to the action server.
    client.send_goal(goal)
   # Waits for the server to finish performing the action.
    wait = client.wait_for_result()
   # If the result doesn't arrive, assume the Server is not available
    if not wait:
        rospy.logerr("Action server not available!")
        rospy.signal_shutdown("Action server not available!")
    else:
    # Result of executing the action
        return client.get_result()   


goalA, goalB, goalC, goalD = create_GoalPoints()

def callback(data):
    if(data.data=="GoToA"):
        print("GO A")
        result = movebase_client(goalA)
        
    elif(data.data=="GoToB"):
        print("GO B")
        result = movebase_client(goalB)
        

    elif(data.data=="GoToC"):
        print("GO C")
        result = movebase_client(goalC)

    elif(data.data=="GoToD"):
        print("GO D")
        result = movebase_client(goalD)

    else:
        print("INVALID QRCODE")



# If the python node is executed as main process (sourced directly)
if __name__ == '__main__':


    try:
       # Initializes a rospy node to let the SimpleActionClient publish and subscribe
        rospy.init_node('movebase_client_py',anonymous=True)
        rospy.Subscriber("/barcode", String, callback)
        rospy.spin()

    except rospy.ROSInterruptException:
        rospy.loginfo("Navigation test finished.")
