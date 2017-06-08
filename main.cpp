#include <iostream>
#include <stdlib.h>
#include "common.h"
#include "seqinfile.h"
//#include "seqoutfile.h"

using namespace std;
/*

cout <<	"\nFeladat: \n Egy  szoveges  allomanyban  taroljuk  egy  evfolyam  ZH  eredmenyet.  Az allomany  minden  soraban  egy-egy  hallgato  adatait  talaljuk:  a  hallgato EHA  kodjat  es  mellette  a  6  db  feladatra  kapott  pontszamat. \n";
cout <<  "  Az  adatok kozott szokoz(ok) es/vagy tabulator jelek talalhatok. Az egyes feladatokra 0-10-ig  lehetett  pontot  kapni,  ha  valaki  nem  oldott  meg  egy  feladatot, akkor  X-et  irtak a pont  helyere. (Ez csak jelzes a feladat hianyara.) Az osztalyzat az osszpontszamtol fugg: 20 ponttol kettes, 30-tol harmas, 40-tol  negyes,  otventol  otos.  Feltehetjuk,  hogy  az  allomany  helyesen  van kitoltve.  Listazza  ki  a  hallgatok  kodjat  �s  osszpontszamat  a  konzolra, valamint  mondja  meg,  hany  otos,  negyes,  harmas,  kettes  es  egyes  jegy szuletett! \n \n \n MEGOLDAS: \n";
*/
int notes [6] = {0,0,0,0,0,0};
int result;
int main()
{

    try{
        string fname;
        cout<<"Add meg a fajl nevet:"; cin>>fname;
        SeqInFile f(fname);
        result = f.First();
        notes[result] = notes[result] + 1;
        if(f.End()){
            cerr<<"Ures a fajl, vagy csupa hibas rekordot tartalmaz! A feldolgozas leall!\n";
            exit(2);
        }

        result = f.Next();
        notes[result] = notes[result] + 1;
        while(!f.End())
        {
            result = f.Next();
            notes[result] = notes[result] + 1;
            if (!f.End()) break;
        };

    }catch (SeqInFile::InpFileError err){
         cerr<<"Problema van input fajllal, a feldolgozas leall!\n";
         exit(1);
    }

    cout<<endl;
    cout<<"\n Jegyek: \n";
    for(int i=1; i<6; ++i)
    {
        cout<<i<<": "<<notes[i]<<endl;
    }

    return 0;
}
