#include "Math.h"
#ifndef DIV_H
#define DIV_H
class Div : Math{
protected:
        vector<string> params;
        string result_string;
        vector<float> converted_params;
public:
        Div(vector<string> input);
        ~Div();
        bool validator();
        void process();
};
#endif
