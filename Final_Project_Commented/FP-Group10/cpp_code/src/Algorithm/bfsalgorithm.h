//! \file bfsalgorithm.h

#pragma once

#include "../Maze/maze.h"
#include "../LandBasedRobot/landbasedrobot.h"

namespace fp
{

/** @brief Defines Algorithm class */
class Algorithm
{
	public:

		/** @brief Algorithm class constructor */
		Algorithm(fp::Maze*);
		
		/** @brief Solve function member of Algorithm class */
        /** @detail Solve function will evaluate maze file based on current attributes
         * from LandBasedRobot
         * */
		void solve(fp::Maze*, fp::LandBasedRobot*);
		
		/** @brief Algorithm Destructor */
		~Algorithm();
};

}

