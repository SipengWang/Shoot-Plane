#include "map.h"

using namespace std;

Map::Map(Gun *gun, Plane *plane)
{
    this->gun = gun;
    this->plane = plane;

    score = 0;
    is_dead = false;
}

void Map::draw(Gun *gun, Plane *plane)
{
    int i, j;

    gun->update();
    plane->update();

    judge_on_target(gun, plane);

    clean_invalid(gun, plane);

    for(int i = 0; i < plane->plane_position_x.size(); i++)
    {
        if(plane->plane_position_x[i] <= 0)
        is_dead = true;
    }


    for(i = 0; i < MAP_HEIGHT; i++)
    for(j = 0; j < MAP_LENGTH; j++)
    map_array[i][j] = MAP_CHAR;

    map_array[gun->gun_position_y][0] = GUN_CHAR;

    for(i = 0; i < gun->bullet_position_x.size(); i++)
    map_array[gun->bullet_position_y[i]][gun->bullet_position_x[i]] = BULLET_CHAR;

    for(i = 0; i < plane->plane_position_x.size(); i++)
    map_array[plane->plane_position_y[i]][plane->plane_position_x[i]] = PLANE_CHAR;


    for(i = 0; i < MAP_HEIGHT; i++)
    {
        for(j = 0; j < MAP_LENGTH; j++)
        cout << map_array[i][j] << ' ';

        cout << endl;
    }

    cout << "Score = " << score << endl;

}

void Map::judge_on_target(Gun *gun, Plane *plane)
{
    for(int i = 0; i < gun->bullet_position_x.size(); i++)
    for(int j = 0; j < plane->plane_position_x.size(); j++)
    {

        if(gun->bullet_position_x[i] >= plane->plane_position_x[j] && 
           gun->bullet_position_y[i] == plane->plane_position_y[j])
           {
               gun->bullet_position_x.erase(gun->bullet_position_x.begin() + i);
               gun->bullet_position_y.erase(gun->bullet_position_y.begin() + i);
               plane->plane_position_x.erase(plane->plane_position_x.begin() + j);
               plane->plane_position_y.erase(plane->plane_position_y.begin() + j);

               score ++;
           }

    }
}

void Map::clean_invalid(Gun *gun, Plane *plane)
{
    int i;

    for(i = 0; i < gun->bullet_position_x.size(); i++)
    {
        if(gun->bullet_position_x[i] > MAP_LENGTH - 1)
        {
            gun->bullet_position_x.erase(gun->bullet_position_x.begin() + i);
            gun->bullet_position_y.erase(gun->bullet_position_y.begin() + i);

        }
    }

    for(i = 0; i < plane->plane_position_x.size(); i++)
    {
        if(plane->plane_position_x[i] < 0)
        {
            plane->plane_position_x.erase(plane->plane_position_x.begin() + i);
            plane->plane_position_y.erase(plane->plane_position_y.begin() + i);
        }
       
    }
}
