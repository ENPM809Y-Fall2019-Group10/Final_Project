//! \file bfsalgorithm.cpp

#include "bfsalgorithm.h"
#include "../API/api.h"
#include "../Direction/direction.h"

/** @brief Breadth First Search (BFS) Algorithm */
/** @detail BFS search algorithm process calls maze pointers to determine cell locations
 * and wall positions. Wall positions are read at the robot current position and clear paths determined.
 * Queue of points are built to find a solution to maze and used to trace path from start to goal
 */
 
 /** @detail Sets start point and goal boundary with green wall markers. */
fp::Algorithm::Algorithm(fp::Maze* maze_ptr)
{
	/** @brief sets start cell to green after clearing previous colors*/
    API::clearAllColor();
	API::setColor(0, 0, 'G');
	
	/** @brief sets goal cell (center of maze) to green */
	maze_ptr->colorCenter('G');
}

/** @detail Solve function uses maze_ptr to read wall positions from current robot position.
 * readWall will return positions of walls present around robot location and identify open paths
 */
void fp::Algorithm::solve(fp::Maze* maze_ptr, fp::LandBasedRobot* wheel_robot)
{
	
	maze_ptr->readWall(0, 0, wheel_robot->get_direction());
	
}

fp::Algorithm::~Algorithm()
{
}