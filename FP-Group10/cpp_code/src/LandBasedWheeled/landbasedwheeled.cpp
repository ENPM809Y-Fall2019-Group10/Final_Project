//! \file landbasedwheeled.cpp

#include "landbasedwheeled.h" //!Includes LandBasedWheeled header file.

//! Constructor Implementation for LandBasedWheeled
fp::LandBasedWheeled::LandBasedWheeled(std::string name, int x, int y, int wheel_number, std::string wheel_type)
: LandBasedRobot(name, x, y), wheel_number_{wheel_number}{
	std::cout << "LandBasedWheeled::LandBasedWheeled is called\n";
	wheel_type_ = new std::string;
	*wheel_type_ = wheel_type;
}

void fp::LandBasedWheeled::GoUp(int x, int y){ //!X and Y positions are pulled to Up function.
	std::cout<<"LandBasedWheeled::GoUp is called"<<std::endl; //!When up is called, cout output is activated identifying GoUp.
}
void fp::LandBasedWheeled::GoDown(int x,int y) //!X and Y positions are pulled to Down function.
{
	std::cout<<"LandBasedWheeled::GoDown is called"<<std::endl;  //!When down is called, cout output is activated identifying GoDown.
}
void fp::LandBasedWheeled::TurnLeft(int x,int y) //!X and Y positions are pulled to Left function.
{
	std::cout<<"LandBasedWheeled::TurnLeft is called"<<std::endl;  //!When left is called, cout output is activated identifying TurnLeft.
}
void fp::LandBasedWheeled::TurnRight(int x,int y) //!X and Y positions are pulled to Right function.
{
	std::cout<<"LandBasedWheeled::TurnRight is called"<<std::endl;  //!When right is called, cout output is activated identifying TurnRight.
}
void fp::LandBasedWheeled::PickUp(std::string name) //!Robot name is pulled to PickUp function.
{
	std::cout<<"LandBasedWheeled::PickUp is called"<<std::endl; //!When pickup is called, cout output is activated identifying PickUp.
}
void fp::LandBasedWheeled::Release(std::string name) //!X and Y positions are pulled to Right function.
{
	std::cout<<"LandBasedWheeled::Release is called"<<std::endl; //!When Release is called, cout output is activated identifying Release.
}

//! FUCNTION ONLY IN LANDBASEDWHEELED.
void fp::LandBasedWheeled::SpeedUp(int){ //! Speed increase int value is pulled to SpeedUp function.
	std::cout<<"LandBasedWheeled::SpeedUp is called"<<std::endl; //!When SpeedUp is called, cout output is activated to identify SpeedUp.
}

fp::LandBasedWheeled::~LandBasedWheeled()
{
	delete wheel_type_;
	std::cout << "LandBasedWheeled::~LandBasedWheeled is called\n";
}