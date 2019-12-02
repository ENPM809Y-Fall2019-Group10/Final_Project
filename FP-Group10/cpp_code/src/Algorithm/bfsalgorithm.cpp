#include "bfsalgorithm.h"
#include "../API/api.h"
#include "../Direction/direction.h"
#include <algorithm>

fp::Algorithm::Algorithm(fp::Maze* maze_ptr)
{
	API::clearAllColor();
	API::setColor(0, 0, 'G');
	//! Color center of the maze with Green
	maze_ptr->colorCenter('G');
	maze_ptr->textCenter("G");
	API::setText(0, 0, "S");
}

void fp::Algorithm::solve(fp::Maze* maze_ptr, fp::LandBasedRobot* wheel_robot)
{
	// Read current location's walls
	maze_ptr->readWall(wheel_robot->get_x(), wheel_robot->get_y(), wheel_robot->get_direction());
	
	// Generate Path from initial location to destination - BFS
	while( not maze_ptr->isGoal(wheel_robot->get_x(), wheel_robot->get_y()) ){
		if( generatePath(maze_ptr, wheel_robot) ){
//			std::cerr << "Path exists to goal node" << std::endl;
			printPath();
			colorPath();
			if( followPath(maze_ptr, wheel_robot) ) std::cerr << "Successfully reached one of the goal cell, Enjoy!!" << std::endl;
//			else std::cerr << "blockage reached!!" << std::endl;
		}
		else{
			std::cerr << "Path does not exist to goal node. Bye, bye!" << std::endl;
			break;
		}
	}		
}

bool fp::Algorithm::generatePath(fp::Maze* maze_ptr, fp::LandBasedRobot* wheel_robot){
	
	//! Clear any existing path on the mms simulator
	API::clearAllColor();
	maze_ptr->colorCenter('G');
	maze_ptr->textCenter("G");
	API::setColor(wheel_robot->get_x(), wheel_robot->get_y(), 'G');
	
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

bool fp::Algorithm::followPath(fp::Maze* maze_ptr, fp::LandBasedRobot* wheel_robot)
{
	auto it=path_.begin()+1; //! Starting from robot's next position for execution
	
	//! loop until the end of path is reached, but if you get a wall in between, stop and return false
	while( it!=path_.end() )
	{
		// If robot is not able to move i.e encountered a wall in its path, return false
		if( not moveRobot(it->first, it->second, maze_ptr, wheel_robot) ){
			return false;
		}
		// After moving to the next cell, read all the walls present in that cell
		maze_ptr->readWall(wheel_robot->get_x(), wheel_robot->get_y(), wheel_robot->get_direction());
		
		++it;// Move to the next cell in path
	}
	return true;
}

bool fp::Algorithm::moveRobot(int next_x, int next_y, fp::Maze* maze_ptr, fp::LandBasedRobot* wheel_robot)
{
	int delta_x = next_x - wheel_robot->get_x(); //find the difference in x values of next cell we need to navigate to and the curr x of the robot
	int delta_y = next_y - wheel_robot->get_y(); //find the difference in y values of next cell we need to navigate to and the curr y of the robot
		
	// Determine the direction based on curr robot direction
	if( delta_x==1 and delta_y==0 ){ // We need to move to the right cell (this is w.r.t. global coordinate system)
		// Check if you can move to the cell or not ==> Check is wall is in your next movement direction
		if( maze_ptr->isWall(wheel_robot->get_x(), wheel_robot->get_y(), fp::Direction::EAST) ) return false;
		// Change the coordinates of the robot
		wheel_robot->set_x(next_x);
		// Print on the mms output window
		std::cerr <<  "Moving to (" << next_x << "," << next_y << ")" << std::endl;
		// Depending on the current direction of the robot, choose appropriate set of actions
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
	else if( delta_x==0 and delta_y==1 ){ // We need to move to the upper cell (this is w.r.t. global coordinate system)
		// Check if you can move to the cell or not ==> Check is wall is in your next movement direction
		if( maze_ptr->isWall(wheel_robot->get_x(), wheel_robot->get_y(), fp::Direction::NORTH) ) return false;
		// Change the coordinates of the robot	
		wheel_robot->set_y(next_y);
		// Print on the mms output window
		std::cerr <<  "Moving to (" << next_x << "," << next_y << ")" << std::endl;
		// Depending on the current direction of the robot, choose appropriate set of actions
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
	else if( delta_x==-1 and delta_y==0 ){ // We need to move to the left cell (this is w.r.t. global coordinate system)
		// Check if you can move to the cell or not ==> Check is wall is in your next movement direction
		if( maze_ptr->isWall(wheel_robot->get_x(), wheel_robot->get_y(), fp::Direction::WEST) ) return false;
		// Change the coordinates of the robot
		wheel_robot->set_x(next_x);
		// Print on the mms output window
		std::cerr <<  "Moving to (" << next_x << "," << next_y << ")" << std::endl;
		// Depending on the current direction of the robot, choose appropriate set of actions
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
	else if( delta_x==0 and delta_y==-1 ){ // We need to move to the bottom cell (this is w.r.t. global coordinate system)
		// Check if you can move to the cell or not ==> Check is wall is in your next movement direction
		if( maze_ptr->isWall(wheel_robot->get_x(), wheel_robot->get_y(), fp::Direction::SOUTH) ) return false;
		// Change the coordinates of the robot	
		wheel_robot->set_y(next_y);
		// Print on the mms output window
		std::cerr <<  "Moving to (" << next_x << "," << next_y << ")" << std::endl;
		// Depending on the current direction of the robot, choose appropriate set of actions
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

void fp::Algorithm::printPath()
{
	std::cerr << "The path is as follows:" << std::endl;
	for(auto it=path_.begin(); it!=path_.end(); ++it)
	{
		std::cerr << it->first << ", " << it->second << std::endl;
	}
}

void fp::Algorithm::colorPath()
{
	for(auto it=path_.begin(); it!=path_.end(); ++it)
	{
		API::setColor(it->first, it->second, 'G');
	}
}

fp::Algorithm::~Algorithm()
{
}
