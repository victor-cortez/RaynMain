//
// Created by victo on 12/24/2021.
//

#ifndef RAYENGINE_INPUTMANAGER_H
#define RAYENGINE_INPUTMANAGER_H

#include <vector>
#include "Player.h"
class InputManager {
    public:
        void processInput(SDL_Event event);
        void addPlayer(Player* inPlayer);
        void update(int dt);

    private:
        std::vector<Player*> myPlayers;
};


#endif //RAYENGINE_INPUTMANAGER_H
