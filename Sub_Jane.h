#include "Math.h"
#ifndef SUB_H
#define SUB_H

class Sub : Math{
protected:
        vector<string> params;
        string result_string;
        vector<float> converted_params;
public:
        Sub(vector<string> input);
        ~Sub();
        bool validator();
        void process();
};
#endif
