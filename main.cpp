#include "common.h"
#include "Var.h"
#include "String.h"
#include "templateVar.h"
#include "templateVar.cpp"

map<string, VAR*> createdVariables;

int main() {
    map<string, VAR*> varMap;
    // varMap["NUMERIC"] = new templateVar<int>;
    // varMap["REAL"] = new templateVar<double>;
    varMap["CHAR"] = new templateVar<char>;
    // varMap["STRING"] = new STRING();
    string line ="";
    ifstream readFile("ExampleFile.txt");
    string name ="";
    while(getline(readFile, line)) {
        stringstream iss(line); // Load line to the string stream
        getline(iss, name, ',');
        VAR * obj = varMap[name];
        if( obj != NULL ) {
            obj -> constructVar(iss);
            obj -> print();
            obj -> setCharValue('p');
            obj -> print();
            obj -> varInsert(createdVariables);
        }
    }
    for( const auto &p : createdVariables ) {
        delete(p.second);
    }
    readFile.close();
    return 0;
}