#include "String.h"
#include "Var.h"
#include "common.h"

STRING::STRING(){
    name = ""; 
    size = 0; 
    value = NULL;
}

STRING::STRING(const string& inName, int inSize, char * inValue) {
    if( inSize > 256 || inSize < 0 || sizeof(inValue)/sizeof(*inValue) > 256 ) {
        cout << "Char array size must not exceed 256" << endl;
        throw;
    }
    name = inName;
    size = inSize;
    value = inValue;
}

void STRING::setStringValue(char a, int i) {
    if( i < size ) {
        value[i] = a;
    } else { 
        cout << "The location is out of range of the variable" << endl;
        throw;
    }
}

char STRING::getStringValue(int i) {
    if( i < size ) {
        return value[i];
    } else {
        cout << "The location is out of range of the variable" << endl;
    }
}

void STRING::print() {
    cout << name << ", "  << size << ", " << value << endl;
}

void STRING::varInsert(map<string, VAR*> &varMap) {
    varMap[name] = this;
}

void STRING::constructVar(stringstream &ss) {
    string str = "";
    getline(ss, str, ',');
    name = str.c_str();
    getline(ss, str, ',');
    size = stoi(str.c_str(), NULL);
    getline(ss, str, ',');
    value = (char*)str.c_str();
}

VAR* STRING::clone(stringstream &ss) {
    STRING * cloneVar = new STRING();
    cloneVar -> constructVar(ss);
    return cloneVar;
}

STRING::~STRING(){}