//! \file landbasedwheeled.cpp

#include "../LandBasedWheeled/landbasedwheeled.h" //!Includes LandBasedWheeled header file.
#include "../API/api.h"
#include "../Direction/direction.h"

//! Constructor Implementation for LandBasedWheeled
fp::LandBasedWheeled::LandBasedWheeled(std::string name, int x, int y, int wheel_number): LandBasedRobot(name, x, y), wheel_number_{wheel_number}{
	std::cout << "LandBasedWheeled::LandBasedWheeled is called\n";
}

void fp::LandBasedWheeled::MoveForward() //!Turn Robot 90 deg clockwise direction.
{
	std::cout<<"LandBasedWheeled::MoveForward is called"<<std::endl;  //!When right is called, cout output is activated identifying TurnRight.
	API::moveForward();
}

void fp::LandBasedWheeled::TurnLeft() //!Turn Robot 90 deg counter-clockwise direction.
{
	std::cout<<"LandBasedWheeled::TurnLeft is called"<<std::endl;  //!When left is called, cout output is activated identifying TurnLeft.
	API::turnLeft();
	switch(direction_){
		case Direction::NORTH : direction_ = Direction::WEST ; break;
		case Direction::EAST  : direction_ = Direction::NORTH; break;
		case Direction::SOUTH : direction_ = Direction::EAST ; break;
		case Direction::WEST  : direction_ = Direction::SOUTH; break;
	}
}
void fp::LandBasedWheeled::TurnRight() //!Turn Robot 90 deg clockwise direction.
{
	std::cout<<"LandBasedWheeled::TurnRight is called"<<std::endl;  //!When right is called, cout output is activated identifying TurnRight.
	API::turnRight();
	switch(direction_){
		case Direction::NORTH : direction_ = Direction::EAST ; break;
		case Direction::EAST  : direction_ = Direction::SOUTH; break;
		case Direction::SOUTH : direction_ = Direction::WEST ; break;
		case Direction::WEST  : direction_ = Direction::NORTH; break;
	}
}

//! FUNCTION ONLY IN LANDBASEDWHEELED.
void fp::LandBasedWheeled::SpeedUp(int delta){ //! Implements the speed increases in robot.
	std::cout<<"LandBasedWheeled::SpeedUp is called"<<std::endl; //!When SpeedUp is called, cout output is activated to identify SpeedUp.
}