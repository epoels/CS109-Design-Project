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
        void varInsert(map<string, VAR*> &varMap);
        virtual void constructVar(stringstream &ss);
        void print();
        VAR * clone(stringstream &ss);
        char getStringValue(int i);
        void setStringValue(char a, int i);
        virtual ~STRING();
};

#endif