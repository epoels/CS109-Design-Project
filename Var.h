#include "common.h"
#ifndef VAR_H
#define VAR_H

class VAR {
    protected:
    public:
    	VAR(){}
        virtual void constructVar(stringstream &ss) = 0;
        virtual void print() = 0;
        virtual void varInsert(map<string, VAR*> &varMap) = 0;
        virtual VAR* clone(stringstream &ss) = 0;
        virtual void setStringValue(char a, int i){}
        virtual void setNumValue(float i){}
        virtual void setCharValue(char a){}
        virtual char getStringValue(int i){}
        virtual int getNumericValue(){ /*return 0; */ }
        virtual double getRealValue(){  /* return 0.0; */}
        virtual char getCharValue(){ /*return ' ';*/ }
    	virtual ~VAR(){}
};

#endif