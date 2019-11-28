#include "maze.h"
#include <iostream>
#include "../API/api.h"
#include "../Direction/direction.h"

fp::Maze::Maze()
{
	// Set the default maze structure with boundary filled with walls, etc.
	for(int x=0; x<WIDTH; ++x){
		for(int y=0; y<HEIGHT; ++y){
			maze[x][y] = 0;
			if(x==0){
				setWall(x, y, Direction::WEST);
			}
			if(y==0){
				setWall(x, y, Direction::SOUTH);
			}
			if(x==WIDTH-1){
				setWall(x, y, Direction::EAST);
			}
			if(y==HEIGHT-1){
				setWall(x, y, Direction::NORTH);
			}
		}
	}
}


//! Read walls at a certain location depending on the direction
void fp::Maze::readWall(int x, int y, char curr_direction)
{
	switch(curr_direction){
		case Direction::NORTH : if(API::wallFront()){
									setWall(x, y, Direction::NORTH);
								};
								if(API::wallRight()){
									setWall(x, y, Direction::EAST);
								};
								if(API::wallLeft()){
									setWall(x, y, Direction::WEST);
								};
								break;
		case Direction::EAST : if(API::wallFront()){
									setWall(x, y, Direction::EAST);
								};
								if(API::wallRight()){
									setWall(x, y, Direction::SOUTH);
								};
								if(API::wallLeft()){
									setWall(x, y, Direction::NORTH);
								};
								break;
		case Direction::SOUTH : if(API::wallFront()){
									setWall(x, y, Direction::SOUTH);
								};
								if(API::wallRight()){
									setWall(x, y, Direction::WEST);
								};
								if(API::wallLeft()){
									setWall(x, y, Direction::EAST);
								};
								break;
		case Direction::WEST : if(API::wallFront()){
									setWall(x, y, Direction::WEST);
								};
								if(API::wallRight()){
									setWall(x, y, Direction::NORTH);
								};
								if(API::wallLeft()){
									setWall(x, y, Direction::SOUTH);
								};
								break;
	}
}

//! Set wall in required direction
void fp::Maze::setWall(int x, int y, char direction)
{
	switch(direction){
		case Direction::NORTH : maze[x][y] |= 1; API::setWall(x, y, Direction::NORTH); break;
		case Direction::EAST : maze[x][y] |= 2; API::setWall(x, y, Direction::EAST); break;
		case Direction::SOUTH : maze[x][y] |= 4;API::setWall(x, y, Direction::SOUTH); break;
		case Direction::WEST : maze[x][y] |= 8; API::setWall(x, y, Direction::WEST) ;break;
	}
}

//! Check if there is a wall at a certain location
bool fp::Maze::isWall(int x, int y, char direction)
{
//	switch(direction){
//		case Direction::NORTH : return (maze[x][y] & 1) != 0 ; break;
//		case Direction::EAST  : return (maze[x][y] & 2) != 0 ; break;
//		case Direction::SOUTH : return (maze[x][y] & 4) != 0 ; break;
//		case Direction::WEST  : return (maze[x][y] & 8) != 0 ; break;
//	}
//	
	return false;	
}

//! Color center of maze
void fp::Maze::colorCenter(char color){
	for(int x=CLLX; x<=CURX; ++x){
		for(int y=CLLY; y<=CURY; ++y){
			API::setColor(x, y, color);
		}
	}
}

//! Print maze for debugging
void fp::Maze::printMaze()
{
	for(int y=HEIGHT-1; y>=0; --y){
		for(int x=0; x<WIDTH; ++x){
			std::cout << static_cast<int>(maze[x][y]) << " ";
		}
		std::cout << std::endl;
	}
}

fp::Maze::~Maze()
{
}