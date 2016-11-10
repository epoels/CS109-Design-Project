#include "Math.h"
#ifndef MULT_H
#define MULT_H

class Mult : Math{
protected:
        vector<string> params;
        string result_string;
        vector<float> converted_params;
public:
        Mult(vector<string> input);
        ~Mult();
        bool validator();
        void process();
};
#endif
