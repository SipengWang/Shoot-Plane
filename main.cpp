#include <iostream>
#include <stdlib.h>
#include "map.h"
#include "index.h"
#include "plane.h"
#include "gun.h"

using namespace std;



void start_game(void)
{
    Plane plane;
    Gun gun;
    Map map(&gun, &plane);

    cout << "*********************INSTRUCTION*********************" << endl;
    cout << "Use [W] and [S] to move the gun. Use [SPACE] to shoot." << endl;

    cout << "Choose Level" << endl;
    cout << "Easy: 1   Middle: 2   Hard: 3" << endl;
    cin >> plane.level; 

    //usleep(INSTRUCTION_SLEEP_TIME);

    while(1)
    {
        map.draw(&gun, &plane);

        if(map.is_dead)
        {
            cout << "Game Over!" << endl;
            break;
        }
        // cout << map.is_dead << endl;
    }
}


int main()
{
    start_game();

    return 0;
}