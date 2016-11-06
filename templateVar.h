#include "Var.h"
#include "common.h"
#ifndef TEMPLATEVAR_H
#define TEMPLATEVAR_H

template<typename T>
class templateVar: public VAR {
    protected:
        string name;
        T value;
    public:
        templateVar();
        templateVar(const string& inName, T val);
        virtual void constructVar(stringstream &ss);
        void print();
        virtual~templateVar();
};

#endif