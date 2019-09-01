#ifndef _plane_h_
#define _plane_h_

#include <stdlib.h>
#include <vector>
#include "index.h"

using namespace std;

class Plane
{
public:
    Plane();

    vector<pair<int, int>> plane_position;

    void update(void);
    int level;
private:
    int count;
    
};

#endif