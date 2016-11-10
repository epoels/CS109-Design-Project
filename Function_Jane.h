#include "templateVar.cpp"
#include "templateVar.h"
#include "Var.h"
#include "helperFunctions.h"

#ifndef FUNCTION_H
#define FUNCTION_H

//Function Base Class
class Function{
protected:
        vector<string> params;

public:
        Function();
        ~Function();
        virtual bool validator();
        virtual void process();
};

#endif
