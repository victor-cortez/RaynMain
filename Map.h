//
// Created by victo on 12/23/2021.
//
#include <vector>
#include <string>
using namespace std;
#ifndef RAYENGINE_MAP_H
#define RAYENGINE_MAP_H


class Map {
    public:
        vector<int> getSize();
        int sizeX;
        int sizeY;
        vector<vector<char>> mapData;
        vector<vector<char>> getMap(){
            return mapData;
        }


};


#endif //RAYENGINE_MAP_H
