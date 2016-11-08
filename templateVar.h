#include "Var.h"
#include "common.h"
#ifndef TEMPLATEVAR_H
#define TEMPLATEVAR_H

// This is a derived class from VAR
// This is a template class because we wanted the value's type to vary
template<typename T>
class templateVar: public VAR {
    protected:
        string name;
        T value;
    public:

    	// default Constructor
        templateVar();

        // parameterized constructor initializing objects based on the params
        templateVar(const string& inName, T val);

        // Inserts a VAR object into a map for further use
        void varInsert(map<string, VAR*> &varMap);

        // initializes data members based off a stringstream
        virtual void constructVar(stringstream &ss);

        // sets the value to the given param, if the types match
        virtual void setNumValue(float i);
        virtual void setCharValue(char a);

        // Helpful debugging funciton, prints VAR object
        void print();

        // returns the value based off of its type, this code definitely could be more generic
        virtual int getNumericValue();
        virtual double getRealValue();
        virtual char getCharValue();

        // Clones a VAR onject, used for multi threading
        VAR * clone(stringstream &ss);

        // Default constructor
        virtual~templateVar();
};

#endif