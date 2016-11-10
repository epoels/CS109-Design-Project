#include "Function.h"
#ifndef OUT_H
#define OUT_H

class Out : Function{
protected:
        vector<string>params;
public:
        Out(vector<string> input);
        ~Out();
        bool validator();
        void process();
};
#endif
