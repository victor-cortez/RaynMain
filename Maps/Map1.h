//
// Created by victo on 12/23/2021.
//

#ifndef RAYENGINE_MAP1_H
#define RAYENGINE_MAP1_H
#include "../Map.h"

class Map1: public Map{
    public:
        Map1(){
            sizeX = 8;
            sizeY = 8;
            mapData = {{0,0,0,0,0,0,0,0},
                                         {0,1,1,0,0,0,0,0},
                                         {0,1,1,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,0}};
        }
        vector<int> getSize();

    private:

};


#endif //RAYENGINE_MAP1_H
