//
// Created by victo on 12/24/2021.
//

#include "InputManager.h"
#include <iostream>
using namespace std;
void InputManager::processInput(SDL_Event event){
    if( event.type == SDL_KEYDOWN || event.type == SDL_KEYUP ){
        switch (event.key.keysym.sym ){
            case SDLK_w:
                myPlayers[0]->isMovingForward = (event.type == SDL_KEYDOWN);
                break;
            case SDLK_s:
                myPlayers[0]->isMovingBackwards = (event.type == SDL_KEYDOWN);
                break;
            case SDLK_a:
                myPlayers[0]->isRotatingLeft = (event.type == SDL_KEYDOWN);
                break;
            case SDLK_d:
                myPlayers[0]->isRotatingRight= (event.type == SDL_KEYDOWN);
                break;
        }
    }
}

void InputManager::update(int dt){
    for (int i = 0; i < myPlayers.size(); i ++){
        if (myPlayers[i]->isMovingForward) {
            myPlayers[i]->moveFront(dt);
            cout<<"Moving front"<<endl;
        }
        if (myPlayers[i]->isMovingBackwards) {
            myPlayers[i]->moveBack(dt);
            cout<<"Moving back"<<endl;
        }
        if (myPlayers[i]->isRotatingLeft) {
            myPlayers[i]->rotateLeft(dt);
            cout<<"Rotate Right"<<endl;
        }
        if (myPlayers[i]->isRotatingRight) {
            myPlayers[i]->rotateRight(dt);
            cout<<"Rotate Left"<<endl;
        }
    }
}


void InputManager::addPlayer(Player* inPlayer){
    myPlayers.push_back(inPlayer);
}