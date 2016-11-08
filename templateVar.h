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
        void varInsert(map<string, VAR*> &varMap);
        virtual void constructVar(stringstream &ss);
        virtual void setNumValue(float i);
        virtual void setCharValue(char a);
        void print();
        virtual int getNumericValue();
        virtual double getRealValue();
        virtual char getCharValue();
        VAR * clone(stringstream &ss);
        virtual~templateVar();
};

#endif