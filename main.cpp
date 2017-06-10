#include <iostream>
#include <stdlib.h>
#include "enor.h"
#include <vector>
#include <string>
#include "tetelek.h"

using namespace std;

/*

cout <<	"\nFeladat: \n Egy  szoveges  allomanyban  taroljuk  egy  evfolyam  ZH  eredmenyet.  Az allomany  minden  soraban  egy-egy  hallgato  adatait  talaljuk:  a  hallgato EHA  kodjat  es  mellette  a  6  db  feladatra  kapott  pontszamat. \n";
cout <<  "  Az  adatok kozott szokoz(ok) es/vagy tabulator jelek talalhatok. Az egyes feladatokra 0-10-ig  lehetett  pontot  kapni,  ha  valaki  nem  oldott  meg  egy  feladatot, akkor  X-et  irtak a pont  helyere. (Ez csak jelzes a feladat hianyara.) Az osztalyzat az osszpontszamtol fugg: 20 ponttol kettes, 30-tol harmas, 40-tol  negyes,  otventol  otos.  Feltehetjuk,  hogy  az  allomany  helyesen  van kitoltve.  Listazza  ki  a  hallgatok  kodjat  �s  osszpontszamat  a  konzolra, valamint  mondja  meg,  hany  otos,  negyes,  harmas,  kettes  es  egyes  jegy szuletett! \n \n \n MEGOLDAS: \n";
*/


int main()
{
    int notes [6] = {0,0,0,0,0,0};
    string fname;
    bool hiba;


    do{
        try{
            hiba=false;
            cout<<"Add meg a fajl nevet: ";
            cin>>fname;
            enor t(fname);
            bool l=false;
            int sum,ind;

            t.first();
            student e; //t.Current();
            if(t.end())
            {
                cout<<"Ures a fajl, nem lehet feldolgozni!\n";
                hiba=true;
                break;
            }
            for(;!t.end(); t.next())
            {
                e = t.Current();
                sum = osszegzes(e.points);
                ind = pointtonote(sum);
                cout<<e.neptun<<" "<<sum<<endl;
                notes[ind] = notes[ind] + 1;
            }

            cout<<endl<<"A jegyek darabszama:"<<endl;
            for(int i = 1; i<6; ++i)
                cout<<i<<": "<<notes[i]<<endl;

        }catch(enor::enorerror err)
        {
            if(err==enor::OpenError)
            {
                cerr<<fname<<" Nem nyithato meg!\n";
                hiba=true;
            }
        }
    }while(hiba);


    return 0;
}
