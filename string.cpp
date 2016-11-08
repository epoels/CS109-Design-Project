#include "String.h"
#include "Var.h"
#include "common.h"

STRING::STRING(){
    name = ""; 
    size = 0; 
    value = NULL;
}

STRING::STRING(const string& inName, int inSize, char * inValue) {
    // if the string is too long, or the given size is too big, don't create this variable
    if( inSize > 256 || inSize < 0 || sizeof(inValue)/sizeof(*inValue) > 256 ) {
        cout << "Char array size must not exceed 256" << endl;
        throw;
    }
    // set data members
    name = inName;
    size = inSize;
    value = inValue;
}

// sets the value at the given index to the char value
void STRING::setStringValue(char a, int i) {
    // we can't change the value of an array if its too big
    if( i < size ) {
        value[i] = a;
    } else { 
        // if it is too big, throw an error
        cout << "The location is out of range of the variable" << endl;
        throw;
    }
}

char STRING::getStringValue(int i) {
    // return the value of the String at index i, if it is in size
    if( i < size ) {
        return value[i];
    } else {
        // else throw an error
        cout << "The location is out of range of the variable" << endl;
        throw;
    }
}

// Prints out Var members for debugging
void STRING::print() {
    cout << name << ", "  << size << ", " << value << endl;
}

// inserts VAR object into a map for later use
void STRING::varInsert(map<string, VAR*> &varMap) {
    varMap[name] = this;
}


void STRING::constructVar(stringstream &ss) {
    string str = "";
    getline(ss, str, ','); // gets the first token before a comma
    ss >> ws // ignore any whitespace before the comma
    name = str.c_str();
    getline(ss, str, ',');
    ss >> ws // ignore any whitespace
    size = stoi(str.c_str(), NULL);
    getline(ss, str, ',');
    value = (char*)str.c_str(); // Cast as a char pointer, so we can set to value
}

// clones VAR object for multi-thread use
VAR* STRING::clone(stringstream &ss) {
    STRING * cloneVar = new STRING(); // create new object
    cloneVar -> constructVar(ss); // initialize it
    return cloneVar; // return
}

//default constructor 
STRING::~STRING(){}