//
// Created by victo on 12/23/2021.
//

#include "TWODRenderer.h"

void TWODRenderer::renderMap(Map *inMap){
    int lenX = inMap->getSize()[0];
    int lenY = inMap->getSize()[1];
    float scaleX =  screenWidth/lenX;
    float scaleY =  screenHeight/lenY;
    vector<vector<char>> mapData = inMap->getMap();
    for (int i = 0; i < lenX; i ++){
        for (int j = 0; j < lenY; j ++){
            int xPos = i*scaleX;
            int yPos = j*scaleY;
            switch( mapData[j][i] ){
                case 0:
                    drawVoid(xPos,yPos,scaleX,scaleY);
                    break;
                case 1:
                    drawWall(xPos,yPos,scaleX,scaleY);
                    break;
                default:
                    drawVoid(xPos,yPos,scaleX,scaleY);
            }
        }
    }
}

void TWODRenderer::drawVoid(int xPos, int yPos,float scaleX, float scaleY){
    SDL_Rect fillRect = {xPos, yPos, (int) scaleX,(int) scaleY};
    SDL_SetRenderDrawColor( renderer,0, 0, 0, 255);
    SDL_RenderFillRect( renderer, &fillRect );

}
void TWODRenderer:: drawWall(int xPos, int yPos,float scaleX, float scaleY){
    SDL_Rect rectOutline = {xPos, yPos,(int)  scaleX, (int) scaleY};
    SDL_SetRenderDrawColor( renderer,255, 255, 255, 255);
    SDL_RenderDrawRect( renderer, &rectOutline );
}