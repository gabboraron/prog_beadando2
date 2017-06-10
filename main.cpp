#define CATCH_CONFIG_MAIN

#include <iostream>
#include <stdlib.h>
#include "enor.h"
#include <vector>
#include <string>
#include "tetelek.h"
#include "catch.hpp"

using namespace std;

/*

cout <<	"\nFeladat: \n Egy  szoveges  allomanyban  taroljuk  egy  evfolyam  ZH  eredmenyet.  Az allomany  minden  soraban  egy-egy  hallgato  adatait  talaljuk:  a  hallgato EHA  kodjat  es  mellette  a  6  db  feladatra  kapott  pontszamat. \n";
cout <<  "  Az  adatok kozott szokoz(ok) es/vagy tabulator jelek talalhatok. Az egyes feladatokra 0-10-ig  lehetett  pontot  kapni,  ha  valaki  nem  oldott  meg  egy  feladatot, akkor  X-et  irtak a pont  helyere. (Ez csak jelzes a feladat hianyara.) Az osztalyzat az osszpontszamtol fugg: 20 ponttol kettes, 30-tol harmas, 40-tol  negyes,  otventol  otos.  Feltehetjuk,  hogy  az  allomany  helyesen  van kitoltve.  Listazza  ki  a  hallgatok  kodjat  �s  osszpontszamat  a  konzolra, valamint  mondja  meg,  hany  otos,  negyes,  harmas,  kettes  es  egyes  jegy szuletett! \n \n \n MEGOLDAS: \n";
*/


TEST_CASE("0.0 eset", "beolvasas teszt")
{
    string filename = "0.txt";
    student diak;

    enor t(filename);
    t.first();
    diak = t.Current();
    CHECK(diak.neptun=="VALAMI");
}

TEST_CASE("0.1 eset", "osszegzes teszt")
{
    string filename = "0.txt";
    int sum;
    student diak;

    enor t(filename);
    t.first();
    diak = t.Current();
    sum = osszegzes(diak.points);
    CHECK(sum==21);
}

TEST_CASE("0.2 eset", "pointtonote teszt")
{
    string filename = "0.txt";
    int sum,point;
    student diak;

    enor t(filename);
    t.first();
    diak = t.Current();
    sum = osszegzes(diak.points);
    point = pointtonote(sum);
    CHECK(point==2);
}

TEST_CASE("1.0 eset", "beolvasas teszt - tobb sor")
{
    string filename = "1.txt";
    int sum,point;
    student diak;

    enor t(filename);
    t.first();
    diak = t.Current();
    t.next();
    diak = t.Current();
    /*sum = osszegzes(diak.points);
    point = pointtonote(sum);*/
    CHECK(diak.neptun == "KORTE");
}

TEST_CASE("1.1 eset", "osszegzes teszt - tobb sor")
{
    string filename = "1.txt";
    int sum,point;
    student diak;

    enor t(filename);
    t.first();
    diak = t.Current();
    t.next();
    diak = t.Current();
    sum = osszegzes(diak.points);
    /*point = pointtonote(sum);*/
    CHECK(sum == 11);
}

TEST_CASE("1.2 eset", "osszegzes teszt - tobb sor")
{
    string filename = "1.txt";
    int sum,point;
    student diak;

    enor t(filename);
    t.first();
    diak = t.Current();
    t.next();
    diak = t.Current();
    sum = osszegzes(diak.points);
    point = pointtonote(sum);

    CHECK(point == 1);
}

TEST_CASE("2 eset", "nincs file vege")
{
    string filename = "1.txt";

    enor t(filename);
    t.first();
    t.next();

    CHECK(t.end() == false);
}

TEST_CASE("3 eset", "file vege")
{
    string filename = "2.txt";

    enor t(filename);
    t.first();
    t.next();
    t.next();

    CHECK(t.end() == true);
}
