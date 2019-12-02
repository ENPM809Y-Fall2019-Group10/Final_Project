#include "bfsalgorithm.h"
#include "../API/api.h"
#include "../Direction/direction.h"
#include <algorithm>

/** @brief Instance of the class Algorithm
 * @details Clears and Sets color and text to the cells in the simulator
 * by calling the API function
 * @param maze_ptr pointer to the array of maze representing each cell in the maze
 * @return void
*/
fp::Algorithm::Algorithm(std::shared_ptr<fp::Maze> maze_ptr)
{
	API::clearAllColor(); //! Clears all the cell color by calling the API function
	API::setColor(0, 0, 'g'); //! Sets the start position cell color by calling the API function
	//! Color center of the maze with Green
	maze_ptr->colorCenter('g');
	maze_ptr->textCenter("G");
	API::setText(0, 0, "S"); //! Sets the text 'S' in the start position of the robot
}

/** @brief Sets the wall on the simulator and Generates the path through BFS search algorithm
 * @details Function sets the wall on the simulator by calling the respective API fucntion and calls the other functions 'generatePath' and 
 * 'followPath' to generate a path through BFS search algorithm and makes the robot to follow the path in the simulator and prints a Success statememt
 * when the robot reaches the goal point
 * @param maze_ptr pointer to the array of maze representing each cell in the maze
 * @param wheel_robot pointer to the robot
 * @return void
*/
void fp::Algorithm::solve(std::shared_ptr<fp::Maze> maze_ptr, std::shared_ptr<fp::LandBasedRobot> wheel_robot)
{
	//! Read current location's walls
	maze_ptr->readWall(wheel_robot->get_x(), wheel_robot->get_y(), wheel_robot->get_direction());
	
	//! Generate Path from initial location to destination - BFS algorithm
	while( not maze_ptr->isGoal(wheel_robot->get_x(), wheel_robot->get_y()) ){
		if( generatePath(maze_ptr, wheel_robot) ){
//			printPath(); //! Prints the path on the simulator for debugging purposes
			colorPath(); //! Color the path in which the robot has to traverse
			
			//! Moves the robot to reach the goal point and prints the statement when it reaches the goal point
			if( followPath(maze_ptr, wheel_robot) ) std::cerr << "Successfully reached one of the goal cells, Enjoy!!" << std::endl;
		}
		else{
			//! Prints the statement when there is no goal exists
			std::cerr << "Path does not exist to goal node. Bye, bye!" << std::endl;
			break;
		}
	}
	return;
}

/** @brief Generates a path for the robot through the Breadth First Search Algorithm from start point to the goal point
 * @details Function implements the Breadth First Search Algorithm and estimate an obstacle(wall) free path for the robot movement.
 * and it returns true when a path is found
 * @param maze_ptr pointer to the array of maze representing each cell in the maze
 * @param wheel_robot pointer to the robot
 * @return bool
*/
 
bool fp::Algorithm::generatePath(std::shared_ptr<fp::Maze> maze_ptr, std::shared_ptr<fp::LandBasedRobot> wheel_robot){
	
	//! Clear any existing path on the mms simulator
	//API::clearAllColor();
	maze_ptr->colorCenter('g');
	//maze_ptr->textCenter("G");
	
	//! Clear path is any stored previously
	path_.clear();
	
	//! Return flag
	bool success = false;
	
	//! set visited cells flag as false
	for(int x=0;x<maze_ptr->WIDTH; ++x){
		for(int y=0;y<maze_ptr->HEIGHT; ++y){
			maze_ptr->setVisited(x, y, false);
		}
	}
	
	//! Create a dummy variable to keep track of parent node
	std::map<int, std::map<int, std::pair<int, int> > > parent;
	
	//! Mark current node as visited
	maze_ptr->setVisited(wheel_robot->get_x(), wheel_robot->get_y(), true);
	
	//! Push initial nodes to queue
	xq_.push(wheel_robot->get_x());
	yq_.push(wheel_robot->get_y());
	
	//! Mark current nodes parent as -1,-1 to identify the start of the search algo
	parent[wheel_robot->get_x()][wheel_robot->get_y()] = std::make_pair(-1, -1);
	
	//! Keep track of current node outside the while loop so as to use it in the end as the ending point
	int curr_x{wheel_robot->get_x()}, curr_y{wheel_robot->get_y()};
	
	//! Loop until a goal is found or the queue are empty(there does not exist a goal!)
	while( not xq_.empty() ){
		
		//! Pop x and y positions from queue
		curr_x = xq_.front();
		curr_y = yq_.front();
		xq_.pop();
		yq_.pop();
				
		//! Check if goal is reached. Exit if true
		if( maze_ptr->isGoal(curr_x, curr_y) ){
			success = true;
			break;
		}
	
		//! Get all neighbours == possible cells it can go from current cell.
		for(int i=0; i<4; ++i){
			if( maze_ptr->isCellValid(curr_x + xarr_[i], curr_y + yarr_[i]) ){
				if( not maze_ptr->isWall(curr_x, curr_y, dir_[i]) ){
					if( not maze_ptr->isVisited(curr_x + xarr_[i], curr_y + yarr_[i]) ){
						maze_ptr->setVisited(curr_x + xarr_[i], curr_y + yarr_[i], true);
						xq_.push(curr_x + xarr_[i]);
						yq_.push(curr_y + yarr_[i]);
						parent[curr_x + xarr_[i]][curr_y + yarr_[i]] = std::make_pair(curr_x, curr_y);
					}
				}
			}
		}
	}

	//! curr_x and curr_y will be the end goal reached by the search algorithm
	path_.push_back(std::make_pair(curr_x, curr_y));
		
	//! Generate the path from goal to start cell
	while( not (curr_x == wheel_robot->get_x() and curr_y == wheel_robot->get_y()) ){
		path_.push_back(parent[curr_x][curr_y]);
		int local_x = parent[curr_x][curr_y].first;
		curr_y = parent[curr_x][curr_y].second;
		curr_x = local_x;
	}
	
	//! Reverse the path to get start to goal cell path
	std::reverse(path_.begin(), path_.end());
	
	//! Clear variables of algorithm once path is generated
	std::queue <int> empty;
	std::swap(xq_, empty);
	std::queue <int> empty1;
	std::swap(yq_, empty1);
	
	return success;
}


/** @brief Makes the robot to traverse in the path obtained through the Breadth First Search Algorithm.
 * @details Function moves the robot by looping the movement process until the end of path is reached, but there is a wall in between cells
 * then it stop and return false.Also if a robot is not able to move when it encountered a wall in its path it return false.
 * Robot is moved to the next cell in the path
 * @param maze_ptr pointer to the array of maze representing each cell in the maze
 * @param wheel_robot pointer to the robot
 * @return bool
*/
bool fp::Algorithm::followPath(std::shared_ptr<fp::Maze> maze_ptr, std::shared_ptr<fp::LandBasedRobot> wheel_robot)
{
	auto it=path_.begin()+1; //! Starting from robot's next position for execution
	
	//! loop until the end of path is reached, but if you get a wall in between, stop and return false
	while( it!=path_.end() )
	{
		//! If robot is not able to move i.e encountered a wall in its path, return false
		if( not moveRobot(it->first, it->second, maze_ptr, wheel_robot) ){
			while( it!= path_.end()-1){
				API::clearColor(it->first, it->second);
				++it;
			}
			return false;
		}
		//! After moving to the next cell, read all the walls present in that cell
		maze_ptr->readWall(wheel_robot->get_x(), wheel_robot->get_y(), wheel_robot->get_direction());
		
		++it;//! Move to the next cell in path
	}
	return true;
}

/** @brief Moves or rotates the robot to reach the next position.
 * @details Function evaluates the direction in which the Robot needs to move by comparing its current position with the previous position
 * in maze. After estimating the direction in which the Robot needs to move, the API function function is called 
 * to execute the respective movement in the simulator output screen.  The 4 cases for Robot movement are North, South, East, or West on the simulator.
 * @param next_x x-location of the cell in which the robot to be moved next
 * @param next_y y-location of the cell in which the robot to be moved next
 * @param maze_ptr pointer to the array of maze representing each cell in the maze
 * @param wheel_robot pointer to the robot
 * @return bool
*/
bool fp::Algorithm::moveRobot(int next_x, int next_y, std::shared_ptr<fp::Maze> maze_ptr, std::shared_ptr<fp::LandBasedRobot> wheel_robot)
{
	int delta_x = next_x - wheel_robot->get_x(); //find the difference in x values of next cell we need to navigate to and the curr x of the robot
	int delta_y = next_y - wheel_robot->get_y(); //find the difference in y values of next cell we need to navigate to and the curr y of the robot

	//! Determine the direction based on curr robot direction
	if( delta_x==1 and delta_y==0 ){ // We need to move to the right cell (this is w.r.t. global coordinate system)
		//! Check if you can move to the cell or not ==> Check is wall is in your next movement direction
		if( maze_ptr->isWall(wheel_robot->get_x(), wheel_robot->get_y(), fp::Direction::EAST) ) return false;
		//!Change the coordinates of the robot
		wheel_robot->set_x(next_x);
		//! Print on the mms output window
		std::cerr <<  "Moving to (" << next_x << "," << next_y << ")" << std::endl;
		//! Sets the color of the cells into Yellow in the given position by calling the API setColor function
		API::setColor(next_x, next_y, 'Y');
		//! Depending on the current direction of the robot, choose appropriate set of actions
		switch( wheel_robot->get_direction() ){
			case fp::Direction::NORTH :
				wheel_robot->TurnRight();
				wheel_robot->MoveForward();
				break;
			case fp::Direction::EAST :
				wheel_robot->MoveForward();
				break;
			case fp::Direction::SOUTH :
				wheel_robot->TurnLeft();
				wheel_robot->MoveForward();
				break;
			case fp::Direction::WEST :
				wheel_robot->TurnRight();
				wheel_robot->TurnRight();
				wheel_robot->MoveForward();
				break;
		}
	}
	else if( delta_x==0 and delta_y==1 ){ //! We need to move to the upper cell (this is w.r.t. global coordinate system)
		//! Check if you can move to the cell or not ==> Check is wall is in your next movement direction
		if( maze_ptr->isWall(wheel_robot->get_x(), wheel_robot->get_y(), fp::Direction::NORTH) ) return false;
		//! Change the coordinates of the robot	
		wheel_robot->set_y(next_y);
		//! Print on the mms output window
		std::cerr <<  "Moving to (" << next_x << "," << next_y << ")" << std::endl;
		//! Sets the color of the cells into Yellow in the given position by calling the API setColor function
		API::setColor(next_x, next_y, 'Y');
		//! Depending on the current direction of the robot, choose appropriate set of actions
		switch( wheel_robot->get_direction() ){
			case fp::Direction::NORTH :
				wheel_robot->MoveForward();
				break;
			case fp::Direction::EAST :
				wheel_robot->TurnLeft();
				wheel_robot->MoveForward();
				break;
			case fp::Direction::SOUTH :
				wheel_robot->TurnLeft();
				wheel_robot->TurnLeft();
				wheel_robot->MoveForward();				
				break;
			case fp::Direction::WEST :
				wheel_robot->TurnRight();
				wheel_robot->MoveForward();
				break;
		}
	}
	else if( delta_x==-1 and delta_y==0 ){ //! We need to move to the left cell (this is w.r.t. global coordinate system)
		//! Check if you can move to the cell or not ==> Check is wall is in your next movement direction
		if( maze_ptr->isWall(wheel_robot->get_x(), wheel_robot->get_y(), fp::Direction::WEST) ) return false;
		//! Change the coordinates of the robot
		wheel_robot->set_x(next_x);
		//! Print on the mms output window
		std::cerr <<  "Moving to (" << next_x << "," << next_y << ")" << std::endl;
		//! Sets the color of the cells into Yellow in the given position by calling the API setColor function
		API::setColor(next_x, next_y, 'Y');
		//! Depending on the current direction of the robot, choose appropriate set of actions
		switch( wheel_robot->get_direction() ){
			case fp::Direction::NORTH :
				wheel_robot->TurnLeft(); 
				wheel_robot->MoveForward();
				break;
			case fp::Direction::EAST :
				wheel_robot->TurnLeft();
				wheel_robot->TurnLeft();
				wheel_robot->MoveForward();
				break;
			case fp::Direction::SOUTH :
				wheel_robot->TurnRight();
				wheel_robot->MoveForward();
				break;
			case fp::Direction::WEST :
				wheel_robot->MoveForward();
				break;
		}
	}
	else if( delta_x==0 and delta_y==-1 ){ //! We need to move to the bottom cell (this is w.r.t. global coordinate system)
		//! Check if you can move to the cell or not ==> Check is wall is in your next movement direction
		if( maze_ptr->isWall(wheel_robot->get_x(), wheel_robot->get_y(), fp::Direction::SOUTH) ) return false;
		//! Change the coordinates of the robot	
		wheel_robot->set_y(next_y);
		//! Print on the mms output window
		std::cerr <<  "Moving to (" << next_x << "," << next_y << ")" << std::endl;
		//! Sets the color of the cells into Yellow in the given position by calling the API setColor function
		API::setColor(next_x, next_y, 'Y');
		//! Depending on the current direction of the robot, choose appropriate set of actions
		switch( wheel_robot->get_direction() ){
			case fp::Direction::NORTH :
				wheel_robot->TurnLeft();
				wheel_robot->TurnLeft();
				wheel_robot->MoveForward();
				break;
			case fp::Direction::EAST :
				wheel_robot->TurnRight();
				wheel_robot->MoveForward();
				break;
			case fp::Direction::SOUTH :
				wheel_robot->MoveForward();				
				break;
			case fp::Direction::WEST :
				wheel_robot->TurnLeft();
				wheel_robot->MoveForward();
				break;
		}
	}
	return true;
}


/** @brief Function printPath() prints the path points on the terminal for debugging purposes.
 * @return void
*/
void fp::Algorithm::printPath()
{
	std::cerr << "The path is as follows:" << std::endl;
	for(auto it=path_.begin(); it!=path_.end(); ++it)
	{
		std::cerr << it->first << ", " << it->second << std::endl; //!Print the path on the simulator terminal
	}
}

/** @brief Function colorPath() colors the path points on the simulator.
 * @return void
*/
void fp::Algorithm::colorPath()
{
	// Starting from start+1 as we do not want to color it's current location with green as it is being recolored with yellow as we move
	for(auto it=path_.begin()+1; it!=path_.end(); ++it)
	{
		API::setColor(it->first, it->second, 'G');
	}
}