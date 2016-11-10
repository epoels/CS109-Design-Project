#include "common.h"
#include "Var.h"
#include "String.h"
#include "templateVar.h"
#include "templateVar.cpp"
#include "helperFunctions.h"
#include "Add.h"
#include "Mult.h"
#include "Sub.h"
#include "Div.h"
#include "Out.h"

typedef void(*ScriptFunction)(stringstream& ss);
map<string, ScriptFunction> functionPointers;

int main() {
    functionPointers["VAR"] = &varHelper;
    functionPointers["ADD"] = &addHelper;
    functionPointers["SUB"] = &subHelper;
    functionPointers["MUL"] = &multHelper;
    functionPointers["DIV"] = &divHelper;
    // functionPointers["ASSIGN"]
    functionPointers["OUT"] = &outHelper;
    // functionPointers["SET_STR_CHAR"]
    // functionPointers["GET_STR_CHAR"]
    // functionPointers["LABEL"]
    // functionPointers["JMP"]
    // functionPointers["JMPZ"]
    // functionPointers["JMPNZ"]
    // functionPointers["JMPGT"]
    // functionPointers["JMPGTE"]
    // functionPointers["JMPLT"]
    // functionPointers["JMPLTE"]
    //functionPointers["SLEEP"] = &sleepHelper;
    string line ="";
    ifstream readFile("ExampleFile.txt");
    string name ="";
    while(getline(readFile, line)) {
        stringstream iss(line);// Load line to the string stream
        getline(iss, name, ' ');
        if( functionPointers.find(name) == functionPointers.end() ) {
            cout << "No valid OPCODE" << endl;
            throw;
        } else {
            (*(functionPointers[name]))(iss);
        }
    }
    //for(map<string, VAR*>::const_iterator it = createdVariables.begin(); it != createdVariables.end(); ++it){it->second->print();}
    deleteVariables();
    readFile.close();
    return 0;
}
