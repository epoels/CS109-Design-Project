#include "Var.h"
#include "common.h"
#ifndef STRING_H
#define STRING_H

// This class is derived from var, and its value is a char array, and has int size
class STRING : public VAR {
    protected:
        string name;
        int size;
        char* value;
    public:

        // default constructor
        STRING();

        // Paramaterized constructor initializing data members from param list
        STRING(const string& inName, int inSize, char* inValue);

        // Inserts a VAR into a map for later use
        void varInsert(map<string, VAR*> &varMap);

        // Initializes data members with values from stringstream
        virtual void constructVar(stringstream &ss);

        // Helpful debugging method, prints out VAR contents
        void print();

        // Clones the VAR object, used for multi-threading
        VAR * clone(stringstream &ss);

        // gets the char value of a VAR at the provided index
        char getStringValue(int i);

        // sets the value at the given index to the char value
        void setStringValue(char a, int i);

        // Default deconstructor
        virtual ~STRING();
};

#endif