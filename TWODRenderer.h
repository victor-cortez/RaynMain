//
// Created by victo on 12/23/2021.
//

#ifndef RAYENGINE_TWODRENDERER_H
#define RAYENGINE_TWODRENDERER_H

#include "Map.h"
#include <SDL2/SDL.h>
class TWODRenderer {
    public:
        void renderMap(Map* inMap);
        void initialize(int sHeight, int sWidth, SDL_Renderer* renderer){
            this->screenHeight = sHeight;
            this->screenWidth = sWidth;
            this->renderer = renderer;
        }

    private:
        SDL_Renderer* renderer;
        int screenHeight;
        int screenWidth;
        void drawVoid(int xPos, int yPos,float scaleX, float scaleY);
        void drawWall(int xPos, int yPos,float scaleX, float scaleY);
};


#endif //RAYENGINE_TWODRENDERER_H
