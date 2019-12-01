//! \file maze.h

#pragma once

#include <map>

namespace fp
{
class Maze
{
	public:
		/** @brief Constructor for Maze class */
		Maze();
		
		/** @brief Destructor for Maze class */
		~Maze();
		
		/** @brief Member functions for Maze class
         * @detail Maze class consists of the following functions for maze manipulation
         * @function printMaze(): Prints maze in command window for debugging
         * @function isWall(): Checks for wall present in specified direction. Returns false if no wall found
         * @function readWall(): Reads presence of wall in maze file from given position and current robot heading 
         * @function setWall(): Sets wall in maze simulator based on discoveries from search algorithm and readWall
         * @function colorCenter(): Colors center of maze to distinguish goal.
         * */
		void printMaze();
		bool isWall(int x, int y, char direction);
		void readWall(int x, int y, char curr_direction);
		void setWall(int x, int y, char direction);
		void colorCenter(char);

        /** @detail clearWall() provides reset to maze output in case of crash.
         * 
         */
		static void clearWall(int x, int y, int direction);
		static bool isKnown(int x, int y, char direction);


	private:
		
		/** @brief The width and height of the maze is preset to 16x16 */
		static const int WIDTH  = 16;
		static const int HEIGHT = 16;
		
		/** @detail The x and y positions of the lower left (Start) and center (Goal) cells.
         * Position of the start and goal cells is determine based on the width and height of the
         * maze file loaded.
         */
		static const int CLLX = (WIDTH  - 1) / 2;
		static const int CLLY = (HEIGHT - 1) / 2;
		static const int CURX = (WIDTH) / 2;
		static const int CURY = (HEIGHT) / 2;
		
		/** @brief Maze is encoded in map data-structure */
        /** @detail Current storage format of map data structure is cell coordinate,
         * followed by boolean for each direction to establish wall presence.
         * @param maze: XX,YY,W(0/1),S(0/1),E(0/1),N(0/1)
         */
		std::map<int, std::map<int, unsigned char>> maze; //! Current storage format is 0000WSEN
};
}