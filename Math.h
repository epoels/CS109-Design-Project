#include "Function.h"
#ifndef MATH_H
#define MATH_H

class Math : Function{
protected:
        vector<string> params;
        vector<float> converted_params;

public:
        Math();
        ~Math();
        int convert(string s);
        virtual bool validator();
        virtual void process();
};

#endif
