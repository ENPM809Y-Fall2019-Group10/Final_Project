#pragma once

#include <map>

namespace fp
{
class Maze
{
	public:
		//! Constructor
		Maze();
		
		//! Destructor
		~Maze();
		
		//!Member Functions
		void printMaze();
		bool isWall(int x, int y, char direction);
		void readWall(int x, int y, char curr_direction);
		void setWall(int x, int y, char direction);
		void colorCenter(char);


		static void clearWall(int x, int y, int direction);
		static bool isKnown(int x, int y, char direction);


	private:
		
		//! The width and height of the maze
		static const int WIDTH  = 16;
		static const int HEIGHT = 16;
		
		//! The x and y positions of the lower left and upper right center cells
		static const int CLLX = (WIDTH  - 1) / 2;
		static const int CLLY = (HEIGHT - 1) / 2;
		static const int CURX = (WIDTH) / 2;
		static const int CURY = (HEIGHT) / 2;
		
		//! maze being encoded in map data-structure
		std::map<int, std::map<int, unsigned char>> maze; //! Current storage format is 0000WSEN
};
}