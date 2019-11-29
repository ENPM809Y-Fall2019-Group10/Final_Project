//! Group 10 - FP
//! \file main.cpp
/*! \mainpage ENPM809Y Group 10
 * Final Project
 * Micromouse Simulation
*/

#include <stdio.h>
#include "./src/LandBasedRobot/landbasedrobot.h"
#include "./src/LandBasedTracked/landbasedtracked.h"
#include "./src/LandBasedWheeled/landbasedwheeled.h"
#include "./src/API/api.h"
#include "./src/Maze/maze.h"
#include "./src/Algorithm/bfsalgorithm.h"

/** @brief Main function
 * @detail Calls on LandBasedRobot class to generate new robot,
 * create instance of provided maze,
 * and calls algorithm class to complete maze search
 */

int main(int argc, char **argv)
{
	printf("Alright, let's start it!!\n");
	
    /** @detail Calls LandbasedRobot class and creates new instance of 
     * robot vehicle from input. Current input preset as:
     * Name: Husky; Starting X: 0; Starting Y: 0
    */
	fp::LandBasedRobot* wheel_robot = new fp::LandBasedWheeled("Husky", 0, 0);
	
	// Create an instance of maze
    /** @brief Creates instance of maze reader. 
     * @detail Reads provided maze file and within maze class.
     * After maze reader completes and return maze pointers, Maze can be printed
     * to simulation display.
     * @param maze_ptr Returned from running Maze class. Can be used to display maze in window.
     */
	fp::Maze* maze_ptr = new fp::Maze();
	maze_ptr->printMaze();
	
	// Create an instance of Algorithm class
    /** @brief Creates instance of Algorithm class
     * @detail Following command generates new instance of algorithm class to run.
     * Breadth First Search algorithm through maze file. 'maze_ptr' is provided to class function
     * for alforithmic searching. After Algorithm is completed, the actions of moving robot are
     * completed based on return from Algorithm class.
     * @param bfs_algo Group of points visited using Breadth First Search (BFS) algorithm
     */
	fp::Algorithm* bfs_algo = new fp::Algorithm(maze_ptr);
	wheel_robot->TurnLeft();
	wheel_robot->TurnLeft();
	wheel_robot->TurnLeft();
    
    /** @detail 
     * After collecting maze structure and robot type, results of the BFS algorithm are sent to Solve
     * function to evaluate and display path from start to goal.
     */
    
	bfs_algo->solve(maze_ptr, wheel_robot);	
	
	
	delete bfs_algo;
	delete maze_ptr;
	delete wheel_robot;
	return 0;
}