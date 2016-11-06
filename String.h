#include "Var.h"
#include "common.h"
#ifndef STRING_H
#define STRING_H

class STRING : public VAR {
    protected:
        string name;
        int size;
        char* value;
    public:
        STRING();
        STRING(const string& inName, int inSize, char* inValue);
        virtual void constructVar(stringstream &ss);
        void print();
        virtual ~STRING();
};

#endif