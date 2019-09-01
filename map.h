#ifndef _map_h_
#define _map_h_

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "gun.h"
#include "plane.h"
#include "index.h"

using namespace std;

class Map
{
public:

    char map_array[MAP_HEIGHT][MAP_LENGTH];
    int score;

    Map(Gun *gun, Plane *plane);
    void draw(Gun *gun, Plane *plane);
    void judge_on_target(Gun *gun, Plane *plane);
    bool is_dead;
    void clean_invalid(Gun *gun, Plane *plane);


private:
    Gun *gun;
    Plane *plane;
};

#endif