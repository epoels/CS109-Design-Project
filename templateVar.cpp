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
    if( ss.fail() ) {
        cout << "Unable to set template value to the speicified type" << endl;
        ss.clear();
        throw;
    }
    return temp;
}

template<typename T>
void templateVar<T>::setNumValue(float i) {
    try {
        value = static_cast<int>(i);
    } catch (std::bad_cast& bc) {
        cout << "Variable type mismatch" << endl;
        throw;
    }
}

template<typename T>
void templateVar<T>::setCharValue(char a) {
    if( strcmp( typeid(value).name(), "c") == 0 ) {
        value = a;
    } else {
        cout << "Types do not match" << endl;
        throw;
    }
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
VAR * templateVar<T>::clone(stringstream &ss) {
    templateVar<T> * cloneVar = new templateVar<T>;
    cloneVar->constructVar(ss);
    return cloneVar;
}

template<typename T>
void templateVar<T>::print() {
    cout << name << ", " << value << endl;
}

template<typename T>
void templateVar<T>::varInsert(map<string, VAR*> &varMap) {
    varMap[name] = this;
}

template<typename T>
templateVar<T>::~templateVar(){}