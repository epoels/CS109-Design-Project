#include "common.h"
#ifndef VAR_H
#define VAR_H

class VAR {
    protected:
    public:
    	VAR();
        virtual void constructVar(stringstream &ss) = 0;
        virtual void print() = 0;
    	virtual ~VAR();
};

#endif