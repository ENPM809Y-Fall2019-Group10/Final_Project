//! \file landbasedtracked.cpp

#include "landbasedtracked.h" //!Includes LandBaseTracked header file.

//!Constructor implementation for LandBasedTracked robot using LandBasedRobot as derived object.
fp::LandBasedTracked::LandBasedTracked(std::string name, int x, int y, std::string track_type) 
: LandBasedRobot(name, x, y){
	std::cout << "LandBasedTracked::LandBasedTracked is called\n";
	track_type_ = new std::string;
	*track_type_ = track_type;
}

void fp::LandBasedTracked::GoUp(int x, int y){  //!X and Y positions are pulled to Up function.
	std::cout<<"LandBasedTracked::GoUp is called"<<std::endl; //!When up is called, cout output is activated identifying GoUp.
}
void fp::LandBasedTracked::GoDown(int x,int y)  //!X and Y positions are pulled to Down function.
{
	std::cout<<"LandBasedTracked::GoDown is called"<<std::endl; //!When down is called, cout output is activated identifying GoDown.
}
void fp::LandBasedTracked::TurnLeft(int x,int y)  //!X and Y positions are pulled to Left function.
{
	std::cout<<"LandBasedTracked::TurnLeft is called"<<std::endl; //!When left is called, cout output is activated identifying TurnLeft.
}
void fp::LandBasedTracked::TurnRight(int x,int y)  //!X and Y positions are pulled to Right function.
{
	std::cout<<"LandBasedTracked::TurnRight is called"<<std::endl; //!When right is called, cout output is activated identifying TurnRight.
}
void fp::LandBasedTracked::PickUp(std::string name) //!Robot type is pulled to Pickup function.
{
	std::cout<<"LandBasedTracked::PickUp is called"<<std::endl; //!When Pickup is called, cout output is activated identifying PickUp.
}
void fp::LandBasedTracked::Release(std::string name) //!Robot type is pulled to Release function.
{
	std::cout<<"LandBasedTracked::Release is called"<<std::endl; //!When Release is called, cout output is activated identifying Release.
}

fp::LandBasedTracked::~LandBasedTracked()
{
	delete track_type_;
	std::cout << "LandBasedTracked::~LandBasedTracked is called\n";
}