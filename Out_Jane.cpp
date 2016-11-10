#include "Function.h"
#include "Out.h"

//OUT CLASS MEMBER IMPLEMENTATION
//constructor
Out::Out(vector<string> input) : params(input.begin(), input.end()){cout << "Out made" << endl;}
//destructor
Out::~Out(){cout << "Out destroyed" << endl;}

//checks number of parameters: not to exceed 12
bool Out::validator(){
        if(params.size()>12){return false;}
        return true;
}
//prints out parameters
void Out::process(){
        if(validator()){
                for(string s : params){cout << s << ", ";}
                cout << endl;
        }
}
