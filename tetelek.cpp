#include "tetelek.h"


int osszegzes(int v[])
{
    int s = 0;
    for(int i=0; i<6; ++i)
    {
        s = s + v[i];
    }
    return s;
}

int pointtonote(int Sum)
{
    if (Sum>=50){ return 5;}
    else if (Sum>=40){ return 4;}
    else if (Sum>=30){ return 3;}
    else if (Sum>=20){ return 2;}
    else { return 1;}
}
