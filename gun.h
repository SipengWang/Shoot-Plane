#ifndef _gun_h_
#define _gun_h_

#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <vector>
#include <semaphore.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/time.h>
#include <ctime>
#include "index.h"


using namespace std;



class Gun
{
public:
    Gun();

    int gun_position_y;
    char input;
    vector<int> bullet_position_x, bullet_position_y;

    void update();
    void get_input();

};

void changemode(int dir);
int kbhit (void);

#endif