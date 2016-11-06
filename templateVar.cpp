#include "templateVar.h"
#include "Var.h"
#include "common.h"

template<typename T>
templateVar<T>::templateVar() {
    cout << "Ok we are constructing an object" << endl;
    name = "";
    value = 0;
}

template<typename T>
templateVar<T>::templateVar(const string& inName, T val) {
    name = inName;
    value = val;
    cout << name << ", " << value << endl;
}

template<typename T>
T convert(const string& s){
    stringstream ss(s);
    T temp;
    ss >> temp;
    return temp;
}

template<typename T>
void templateVar<T>::constructVar(stringstream &ss) {
    string str ="";
    getline(ss,str,',');
    name = str.c_str();
    getline(ss,str,',');
    value = convert<T>(str.c_str());
}

template<typename T>
void templateVar<T>::print() {
    cout << name << ", " << value << endl;
}

template<typename T>
templateVar<T>::~templateVar(){}