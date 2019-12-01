//! \file maze.cpp

#include "maze.h"
#include <iostream>
#include "../API/api.h"
#include "../Direction/direction.h"

/** @brief Maze class set for maze file interpretation
 * @detail Maze class interprets provided maze file for analysis.
 * Maze default size is set to 16x16 cells. Functions in Maze class are designed
 * to manipulate and set maze characteristics in mouse simulator. Outputs are mostly 
 * to simulator API.
 */
 
fp::Maze::Maze()
{
	/** @detail Set the default maze structure with boundary filled with walls.
     * This establishes a perimeter around the maze area. This area will be populated
     * by maze walls as the maze feature runs. Walls are set in the North, East, South,
     * and West directions.
     */
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


/** @detail
 * Function readwall evalutates the provided X and Y coordinate position with current heading for the presence of
 * a wall in each direction and set in the maze simulator by calling sim API. In each heading direction case, setWall is
 * called to set wall in maze. The 4 cases are North, South, East, or West heading of the simulation mouse/robot.
 */
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

/** @detail 
 * Function setWall uses simulator API to set wall in required direction. Called during readwall function.
 * @return 0; Output is to mouse simulator to set wall.
 */
void fp::Maze::setWall(int x, int y, char direction)
{
	switch(direction){
		case Direction::NORTH : maze[x][y] |= 1; API::setWall(x, y, Direction::NORTH); break;
		case Direction::EAST : maze[x][y] |= 2; API::setWall(x, y, Direction::EAST); break;
		case Direction::SOUTH : maze[x][y] |= 4;API::setWall(x, y, Direction::SOUTH); break;
		case Direction::WEST : maze[x][y] |= 8; API::setWall(x, y, Direction::WEST) ;break;
	}
}

/** @detail Function isWall checks if wall is present in specifieed direction.
 * If wall is not present: @return false
 */
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

/** @detail Function colorCenter sets different color to border walls of maze center.
 * 
 */
void fp::Maze::colorCenter(char color){
	for(int x=CLLX; x<=CURX; ++x){
		for(int y=CLLY; y<=CURY; ++y){
			API::setColor(x, y, color);
		}
	}
}

/** @detail Function printMaze prints maze in command window for debuggin purposes
 * 
 */
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