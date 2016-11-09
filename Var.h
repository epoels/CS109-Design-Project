#include "common.h"
#ifndef VAR_H
#define VAR_H

// This is a base class that follows the structure of the example from class 14
class VAR {
    protected:
    public:
    	// default constructor
    	VAR(){}

    	// Reads the data from the stringstream and assigns values
        virtual void constructVar(stringstream &ss) = 0;

        // Helpful debugging method, prints out variable
        virtual void print() = 0;

        // Inserts a created variable pointer into a map for later use
        virtual void varInsert(map<string, VAR*> &varMap) = 0;

        // Clones the object just created, used for mult-threading
        virtual VAR* clone(stringstream &ss) = 0;

        // sets a char in a string variable at the given index to the given value
        virtual void setStringValue(char a, int i){}

        // Assigns a pointer of type char to a String VAR
        virtual void assignString(string a){}

        // sets the number value of VAR to the given value
        virtual void setNumValue(float i){}

        // sets the char value of a VAR to the given value
        virtual void setCharValue(char a){}

        // gets the char value of a string at the given index
        virtual char getStringValue(int i){}

        // returns the value of Var object
        virtual int getNumericValue(){}
        virtual double getRealValue(){}
        virtual char getCharValue(){}

        // default constructor
    	virtual ~VAR(){}
};

#endif