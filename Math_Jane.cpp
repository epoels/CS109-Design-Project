#include "Math.h"

//constructor
Math::Math(){cout << "Math made" << endl;}
//destructor
Math::~Math(){cout << "Math destroyed" << endl;}

//convert string parameter to workable type: used by all derived arithmetic classes
int Math::convert(string s){
        //if parameter is variable
        if(s[0]=='$'){ return 1;}
        //if parameter is number
        else if(isdigit(s[0])){return 2; }
        //all other parameter types are invalid
        else {return 0;}
}

//checks parameter list, validates type: implemented in derived classes
bool Math::validator(){}
//process implemented in derived classes
void Math::process(){cout << "MATH processing..." << endl;}
