#include "enor.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

enor::enor(const string& fname)
{
    x.open(fname.c_str());
    if(x.fail())
    {
        throw OpenError;
    }else
    {
        cout<<fname<<" file feldolgozasa megkezdodott.\n";
    }
}

void enor::first()
{
    next();
}

void enor::next()
{
    read();
}

void enor::read()
{
    string tmp;
    string tmp2;
    int i = 0;

    getline(x,tmp);
    istringstream ss(tmp);
    sx = x.fail()? abnorm : norm;

    if(sx==norm){
        ss>>elem.neptun;
        while(ss >> tmp2)
        {
            if(tmp2 == "X")
            {
                elem.points[i] = 0;
            } else
            {
                elem.points[i] = atoi(tmp2.c_str());
            }
            ++i;
        }
        /*cout<<elem.neptun<<" ";
        for(int j=0; j<6; ++j)
            cout<<elem.points[j]<<" ";
        cout<<endl;*/
    }
}
/*
vetites enor::current() const
{
    return dx;
}
*/
bool enor::end() const
{
    return sx==abnorm;
}
