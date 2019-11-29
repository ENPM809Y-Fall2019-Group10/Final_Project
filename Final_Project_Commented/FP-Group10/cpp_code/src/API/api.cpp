//! \file api.cpp

#include "api.h"
#include <cstdlib>
#include <iostream>

/** @detail mazeWidth function requests maze width from API and returns
 * maze width information.
 * @param response becomes a constant string to verify response was received from API
 * @return API mazeWidth returns integer with maze width for analysis
 */
int fp::API::mazeWidth() {
    std::cout << "mazeWidth" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

/** @detail mazeHeight function requests maze height from API and returns 
 * maze height information.
 * @param response becomes constant string to verify response was received from API
 * @return API mazeHeight returns integer with maze height for analysis
 */
int fp::API::mazeHeight() {
    std::cout << "mazeHeight" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

/** @detail wallFront function checks for wall infront of robot based on current heading
 * @param response becomes a constant string to verify response was received from API
 * @return API wallFront returns boolean to identify if forward path is clear or blocked.
 * True is returned if wall is present.
 */
bool fp::API::wallFront() {
    std::cout << "wallFront" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

/** @detail wallRight function checks for wall to right of robot based on current heading
 * @param response becomes a constant string to verify response was received from API.
 * @return API wallRight returns boolean to identify if right path is clear or blocked.
 * True is returned if wall is present.
 */
bool fp::API::wallRight() {
    std::cout << "wallRight" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

/** @detail wallLeft function checks for wall to left of robot based on current heading
 * @param response becomes a constant string to verify response was received from API.
 * @return API wallLeft returns boolean to identify if left path is clear or blocked.
 * True is returned if wall is present.
 */
bool fp::API::wallLeft() {
    std::cout << "wallLeft" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

/** @detail moveForward function moves robot position forward if path is clear.
 * @param response is constant string to verify response was received from API after
 * action is completed.
 */
void fp::API::moveForward() {
    std::cout << "moveForward" << std::endl;
    std::string response;
    std::cin >> response;
    if (response != "ack") {
        std::cerr << response << std::endl;
        throw;
    }
}

/** @detail turnRight function rotates robot clockwise if rotation is needed
 * @param response is constant string to verify response was received from API after
 * action is completed.
 */
void fp::API::turnRight() {
    std::cout << "turnRight" << std::endl;
    std::string ack;
    std::cin >> ack;
}

/** @detail turnLeft function rotates robot counter-clockwise if rotation is needed
 * @param response is constant string to verify response was received from API after
 * action is completed.
 */
void fp::API::turnLeft() {
    std::cout << "turnLeft" << std::endl;
    std::string ack;
    std::cin >> ack;
}

/** @detail setWall function sets wall in system memory at the location and direction around
 * current position
 * @param x: Current X position
 * @param y: Current Y position
 * @direction: Desired heading
 */
void fp::API::setWall(int x, int y, char direction) {
    std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}

/** @detail clearWall function clears wall at specified position.
 * @param x: Current X position
 * @param y: Current Y position
 * @direction: Desired heading
 */
void fp::API::clearWall(int x, int y, char direction) {
    std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}

/** @detail setColor function defines wall color for specified wall position. This can be used to
 * identify discovered walls during movement.
 * @param x: Current X position
 * @param y: Current Y position
 * @direction: Desired heading
 */
void fp::API::setColor(int x, int y, char color) {
    std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}

/** @detail clearColor function removes defined wall color at specific location.
 * @param x: Current X position
 * @param y: Current Y position
 * @direction: Desired heading
 */
void fp::API::clearColor(int x, int y) {
    std::cout << "clearColor " << x << " " << y << std::endl;
}

/** @detail clearAllColor function removes defined wall color at all locations.
 */
void fp::API::clearAllColor() {
    std::cout << "clearAllColor" << std::endl;
}

/** @detail setText function uses API feature to write text at specific x,y cell position.
 * Can be used to number specific cells or assign weight values if weighted search methods are used.
 * @param text: String text to be written in cell position X,Y
 */
void fp::API::setText(int x, int y, const std::string& text) {
    std::cout << "setText " << x << " " << y << " " << text << std::endl;
}

/** @detail clearText function uses API feature to clear text at specific x,y cell position.
 */
void fp::API::clearText(int x, int y) {
    std::cout << "clearText " << x << " " << y << std::endl;
}

/** @detail clearAllText function uses API feature to clear text at all cell position.
 */
void fp::API::clearAllText() {
    std::cout << "clearAllText" << std::endl;
}

/** @detail wasReset function uses API feature to reset maze simulator. Can be used
 * in case of crash to reset path search and restart from beginning.
 * Function will provide response when process is completed.
 * @return boolean true if system reset was completed
 */
bool fp::API::wasReset() {
    std::cout << "wasReset" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

/** @detail ackReset function resets ack response from API. Used for verification when API
 * functions are completed.
 */
void fp::API::ackReset() {
    std::cout << "ackReset" << std::endl;
    std::string ack;
    std::cin >> ack;
}