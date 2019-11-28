//! Group 10 - FP
//! \file main.cpp

#include <stdio.h>
#include "./src/LandBasedRobot/landbasedrobot.h"
#include "./src/LandBasedTracked/landbasedtracked.h"
#include "./src/LandBasedWheeled/landbasedwheeled.h"
#include "./src/API/api.h"
#include "./src/Maze/maze.h"
#include "./src/Algorithm/bfsalgorithm.h"

int main(int argc, char **argv)
{
	printf("Alright, let's start it!!\n");
	
	fp::LandBasedRobot* wheel_robot = new fp::LandBasedWheeled("Husky", 0, 0);
	
	// Create an instance of maze
	fp::Maze* maze_ptr = new fp::Maze();
	maze_ptr->printMaze();
	
	// Create an instance of Algorithm class
	fp::Algorithm* bfs_algo = new fp::Algorithm(maze_ptr);
	wheel_robot->TurnLeft();
	wheel_robot->TurnLeft();
	wheel_robot->TurnLeft();
	bfs_algo->solve(maze_ptr, wheel_robot);	
	
	
	delete bfs_algo;
	delete maze_ptr;
	delete wheel_robot;
	return 0;
}