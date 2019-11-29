//!Group 10 - fp
//! \file landbasedrobot.cpp


#include "landbasedrobot.h" //!Includes basic LandBasedRobot header file for methods and attribute access.

/** @brief LandBasedRobot List of attributes */
/** @param name_: Name of robot
 * @param speed_: Current speed of robot
 * @param width_: Width of robot chassis
 * @param height_: Height of robot chassis
 * @param capacity_: Payload capacity of robot
 * @param x_: Current X position of robot
 * @param y_: Current Y position of robot
 * @param direction_: Current heading of robot. Will be either N, S, E, or W
 */
fp::LandBasedRobot::LandBasedRobot(std::string name, int x, int y, double speed, double width, double length, double height, double capacity, char direction)
: name_{name}, speed_{speed}, width_{width}, length_{length}, height_{height}, capacity_{capacity}, x_{x}, y_{y}, direction_{direction}{}