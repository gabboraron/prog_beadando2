#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "data.h"

using namespace std;

enum status{norm,abnorm};

class enor{
    public:
        enor(const std::string&);
        enum enorerror{OpenError};
        void first();
        void next();
        student Current() const { return elem; }
        bool end() const;
        student elem;
    private:
        std::ifstream x;
        status sx;
        void read();
};


#endif // ENOR_H_INCLUDED
