//
// Created by victo on 12/23/2021.
//

#include "Player.h"
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
void Player::moveFront(int dt){
    xPos += frontalSpeed*dt*cos(rotationAngle);
    yPos -= frontalSpeed*dt*sin(rotationAngle);
    //Don't let the player scape
    xPos = std::max(std::min(xPos,(float) screenWidth), (float) 0);
    yPos = std::max(std::min(yPos,(float) screenHeight), (float) 0);
    cout<<xPos<<" "<<yPos;
}
void Player::moveBack(int dt){
    xPos -= backSpeed*dt*cos(rotationAngle);
    yPos += backSpeed*dt*sin(rotationAngle);
    //Don't let the player scape
    xPos = std::max(std::min(xPos,(float) screenWidth), (float) 0);
    yPos = std::max(std::min(yPos,(float) screenHeight), (float) 0);
}
void Player::rotateLeft(int dt){
    rotationAngle -= rotationSpeed*dt;
    rotationAngle = fmod(rotationAngle , 2*M_PI);
}
void Player::rotateRight(int dt){
    rotationAngle += rotationSpeed*dt;
    rotationAngle = fmod(rotationAngle , 2*M_PI);
}

void Player::renderPlayer(){
    SDL_Rect fillRect = {(int) xPos, (int) yPos, xSize,ySize};
    SDL_SetRenderDrawColor( renderer,255, 0, 0, 255);
    SDL_RenderFillRect( renderer, &fillRect );
    float lineLength = screenWidth*0.02;
    int x1 = (int) xPos;
    int y1 = (int) yPos;
    int x2 = (int) xPos + lineLength*cos(rotationAngle);
    int y2 = (int) yPos - lineLength*sin(rotationAngle);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

}