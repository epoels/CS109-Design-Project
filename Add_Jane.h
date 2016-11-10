#include "Math.h"

#ifndef ADD_H
#define ADD_H

class Add : Math{
protected:
        vector<string> params;
        string result_string;
        vector<float> converted_params;
public:
        Add(vector<string> input);
        ~Add();
        bool validator();
        void process();
};

#endif
