#include "seqinfile.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

SeqInFile::SeqInFile(string fname)
{
    if(fname.size()<1) fname="inp.txt";
    f.open(fname.c_str());
    if(f.fail()){
        sf=abnorm;
        throw MissingFile;
    }
}

int SeqInFile::First()
{
    return Next();
}

int SeqInFile::Next()
{
    int s;
    bool hiba;
    do{
        hiba=false;
        try{
            s = read();
        }catch(SeqInFile::InpFileError err){
            cerr<<"Hibas rekord:"<<sor<<endl;
            hiba=true;
            cerr<<"A rekord kimarad a feldolgozasbol!\n\n";
        }
    }while(hiba && !End());
    return s;
}



int SeqInFile::read()
{
    f.clear();
    getline(f,sor);
   // cout<<sor<<endl;
    if(!f.fail()){

        sf = norm;
        istringstream ss(sor);


        string neptun;
        int points [6] = {};
        char a;
        int a1,s;
        ss>>neptun;

        for(int i =0; i<6; ++i)
        {
            ss>>a;
            if(a != 'X'){a1 = (int)a- 48;}else{a1 = 0;}
            points[i] = a1;
        }

        s = osszegzes(points);
        cout<<neptun<<" "<<s<<endl;
        s = pointtonote(s);
        //szamlalas(v,s);
        return s;
    } else sf = abnorm;

}


int SeqInFile::osszegzes(int v[])
{
    int s = 0;
    for(int i=0; i<6; ++i)
    {
        s = s + v[i];
    }
    return s;
}

int SeqInFile::pointtonote(int Sum)
{
    if (Sum>=50){ return 5;}
    else if (Sum>=40){ return 4;}
    else if (Sum>=30){ return 3;}
    else if (Sum>=20){ return 2;}
    else { return 1;}
}
/*
szamlalas(int v[], int s)
{
    v[s] = v[s] + 1;
}
*/
