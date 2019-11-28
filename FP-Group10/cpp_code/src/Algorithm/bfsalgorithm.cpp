#include "bfsalgorithm.h"
#include "../API/api.h"
#include "../Direction/direction.h"

fp::Algorithm::Algorithm(fp::Maze* maze_ptr)
{
	API::clearAllColor();
	API::setColor(0, 0, 'G');
	
	//! Color center of the maze with Green
	maze_ptr->colorCenter('G');
}

void fp::Algorithm::solve(fp::Maze* maze_ptr, fp::LandBasedRobot* wheel_robot)
{
	
	maze_ptr->readWall(0, 0, wheel_robot->get_direction());
	
}

fp::Algorithm::~Algorithm()
{
}