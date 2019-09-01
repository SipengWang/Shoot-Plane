#include "gun.h"

using namespace std;

void changemode(int dir)
{
    static struct termios oldt, newt;
 
    if ( dir == 1 )
    {
        tcgetattr( STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    }
    else
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
 
int kbhit (void)
{
    struct timeval tv;
    fd_set rdfs;
 
    tv.tv_sec = 0;
    tv.tv_usec = 0;
 
    FD_ZERO(&rdfs);
    FD_SET (STDIN_FILENO, &rdfs);
 
    select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
}

Gun::Gun()
{
    gun_position_y = MAP_HEIGHT / 2;
    input = 'p';
}

void Gun::update()
{
    get_input();

    if(input ==  'w')
    {
        if(gun_position_y > 0)
        gun_position_y --;
    }

    if (input == 's')
    {
        if(gun_position_y < MAP_HEIGHT - 1)
        gun_position_y ++;
    }

    if(input == ' ')
    {
        bullet_position_x.push_back(0);
        bullet_position_y.push_back(gun_position_y);
    }

    for(int i = 0; i < bullet_position_x.size(); i++)
    bullet_position_x[i] += 1;

    input = 'p';
    


}


void Gun::get_input()
{
    clock_t start;
    start = clock();
    changemode(1); 
    while (clock() - start < SLEEP_TIME)
    {
        if(kbhit())
        {
            input = getchar();
        }
    }
    changemode(0);   
}
