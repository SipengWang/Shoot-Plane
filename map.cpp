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

    for(int i = 0; i < plane->plane_position.size(); i++)
    {
        if(plane->plane_position[i].first <= 0)
        is_dead = true;
    }


    for(i = 0; i < MAP_HEIGHT; i++)
    for(j = 0; j < MAP_LENGTH; j++)
    map_array[i][j] = MAP_CHAR;

    map_array[gun->gun_position_y][0] = GUN_CHAR;

    for(i = 0; i < gun->bullet_position.size(); i++)
    map_array[gun->bullet_position[i].second][gun->bullet_position[i].first] = BULLET_CHAR;

    for(i = 0; i < plane->plane_position.size(); i++)
    map_array[plane->plane_position[i].second][plane->plane_position[i].first] = PLANE_CHAR;


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
    for(int i = 0; i < gun->bullet_position.size(); i++)
    for(int j = 0; j < plane->plane_position.size(); j++)
    {

        if(gun->bullet_position[i].first >= plane->plane_position[j].first && 
           gun->bullet_position[i].second == plane->plane_position[j].second)
           {
               gun->bullet_position.erase(gun->bullet_position.begin() + i);
               //gun->bullet_position_y.erase(gun->bullet_position_y.begin() + i);
               plane->plane_position.erase(plane->plane_position.begin() + j);
               //plane->plane_position_y.erase(plane->plane_position_y.begin() + j);

               score ++;
           }

    }
}

void Map::clean_invalid(Gun *gun, Plane *plane)
{
    int i;

    for(i = 0; i < gun->bullet_position.size(); i++)
    {
        if(gun->bullet_position[i].first > MAP_LENGTH - 1)
        {
            gun->bullet_position.erase(gun->bullet_position.begin() + i);
            //gun->bullet_position_y.erase(gun->bullet_position_y.begin() + i);

        }
    }

    for(i = 0; i < plane->plane_position.size(); i++)
    {
        if(plane->plane_position[i].first < 0)
        {
            plane->plane_position.erase(plane->plane_position.begin() + i);
            //plane->plane_position_y.erase(plane->plane_position_y.begin() + i);
        }
       
    }
}
