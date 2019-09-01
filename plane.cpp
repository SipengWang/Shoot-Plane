#include "plane.h"

using namespace std;

Plane::Plane()
{

    count = 0;
}

void Plane::update()
{
    if((count %= (10 / level)) == 0)
    {
        int new_plane_position_y;

        new_plane_position_y = rand() % MAP_HEIGHT;

        plane_position.push_back(make_pair(MAP_LENGTH, new_plane_position_y));

        for(int i = 0; i < plane_position.size(); i++)
        plane_position[i].first --;
    }

    count ++;
}