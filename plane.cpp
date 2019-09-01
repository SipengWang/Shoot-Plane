#include "plane.h"

using namespace std;

Plane::Plane()
{
    plane_position_x = {MAP_LENGTH};
    plane_position_y = {MAP_HEIGHT / 2};
    count = 0;
}

void Plane::update()
{
    if((count %= (10 / level)) == 0)
    {
        int new_plane_position_y;

        new_plane_position_y = rand() % MAP_HEIGHT;

        plane_position_x.push_back(MAP_LENGTH);
        plane_position_y.push_back(new_plane_position_y);

        for(int i = 0; i < plane_position_x.size(); i++)
        plane_position_x[i] --;
    }

    count ++;
}