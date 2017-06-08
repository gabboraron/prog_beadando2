#ifndef SEQINFILE_H_INCLUDED
#define SEQINFILE_H_INCLUDED

#include <vector>
#include <fstream>
#include <string>

#include "common.h"
#include "data.h"
//#include "tetelek.h"

enum Status{abnorm, norm};

class SeqInFile
{
    public:
        enum InpFileError{MissingFile,MissingResult,WrongResultFormat};
        SeqInFile(std::string fname="");
        int First();
        int Next();
        bool End() const { return sf==abnorm;}
        Csapat Current() const { return elem; }
    private:
        int osszegzes(int []);
        //int szamlalas(int [], int);
        int pointtonote(int);

        std::ifstream f;
        Csapat elem;
        Status sf;
        std::string sor;
        int read();
};


#endif // SEQINFILE_H_INCLUDED
