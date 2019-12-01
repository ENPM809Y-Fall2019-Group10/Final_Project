#pragma once

#include "../Maze/maze.h"
#include "../LandBasedRobot/landbasedrobot.h"
#include "../Direction/direction.h"
#include <queue>

namespace fp
{
class Algorithm
{
	public:

		//! Constructor
		Algorithm(fp::Maze*);
		
		//! Member functions
		void solve(fp::Maze*, fp::LandBasedRobot*);
		bool generatePath(fp::Maze*, fp::LandBasedRobot*);
		bool followPath(fp::Maze*, fp::LandBasedRobot*);
		bool moveRobot(int, int, fp::Maze*, fp::LandBasedRobot*);
		void printPath();
		void colorPath();
		
		//!Destructor
		~Algorithm();
		
	private:
		std::vector<std::pair<int, int> > path_; // To track the path from current location to goal node.
		std::queue<int> xq_; // Queue to store x coordinates as we traverse path
		std::queue<int> yq_; // Queue to store y coordinates as we traverse path
		int xarr_[4]{0, 1, 0, -1}; // x list of possible movements on the grid. Order is in down, right, up and left i.e S, E, N, W
		int yarr_[4]{-1, 0, 1, 0}; // y list of possible movements on the grid. Order is in down, right, up and left i.e S, E, N, W
		char dir_[4]{fp::Direction::SOUTH, fp::Direction::EAST, fp::Direction::NORTH, fp::Direction::WEST}; // this list of directions is corresponding to the movement above
};
}

