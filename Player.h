//
// Created by victo on 12/23/2021.
//

#ifndef RAYENGINE_PLAYER_H
#define RAYENGINE_PLAYER_H

#include <SDL2/SDL.h>
class Player {
    public:
        void initialize(int sHeight, int sWidth, SDL_Renderer* renderer){
            this->screenHeight = sHeight;
            this->screenWidth = sWidth;
            this->renderer = renderer;
            setPlayerPos(0,0);
        }
        void setPlayerPos(int xPos, int yPos){
            xPos = (float) xPos;
            yPos = (float) yPos;
        }
        void moveFront(int dt);
        void moveBack(int dt);
        void rotateLeft(int dt);
        void rotateRight(int dt);
        void renderPlayer();
        bool isMovingForward = false;
        bool isMovingBackwards = false;
        bool isRotatingLeft = false;
        bool isRotatingRight = false;
    private:
        float xPos;
        float yPos;
        int screenHeight;
        int screenWidth;
        SDL_Renderer* renderer;
        float rotationAngle = 0;
        float frontalSpeed = 0.01;
        float backSpeed = 0.01;
        float rotationSpeed = 0.004;
        int xSize = 2;
        int ySize = 2;


};


#endif //RAYENGINE_PLAYER_H
