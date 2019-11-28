#pragma once

#include "../Maze/maze.h"
#include "../LandBasedRobot/landbasedrobot.h"

namespace fp
{

class Algorithm
{
	public:

		//! Constructor
		Algorithm(fp::Maze*);
		
		//! Member functions
		void solve(fp::Maze*, fp::LandBasedRobot*);
		
		//!Destructor
		~Algorithm();
};

}

