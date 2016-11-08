#include "common.h"
#include "Var.h"
#include "String.h"
#include "templateVar.h"
#include "templateVar.cpp"
#include "helperFunctions.h"

typedef void(*ScriptFunction)(stringstream& ss);
map<string, ScriptFunction> functionPointers;

int main() {
    functionPointers["VAR"] = &varHelper;
    // functionCodes["ADD"]
    // functionCodes["SUB"]
    // functionCodes["MUL"]
    // functionCodes["DIV"]
    // functionCodes["ASSIGN"]
    // functionCodes["OUT"]
    // functionCodes["SET_STR_CHAR"]
    // functionCodes["GET_STR_CHAR"]
    // functionCodes["LABEL"]
    // functionCodes["JMP"]
    // functionCodes["JMPZ"]
    // functionCodes["JMPNZ"]
    // functionCodes["JMPGT"]
    // functionCodes["JMPGTE"]
    // functionCodes["JMPLT"]
    // functionCodes["JMPLTE"]
    functionPointers["SLEEP"] = &sleepHelper;
    string line ="";
    ifstream readFile("ExampleFile.txt");
    string name ="";
    while(getline(readFile, line)) {
        stringstream iss(line);// Load line to the string stream
        getline(iss, name, ',');
        // VAR * obj = varMap[name];
        // if( obj != NULL ) {
        //     iss >> ws;
        //     obj -> constructVar(iss);
        //     obj -> varInsert(createdVariables);
        // }
        if( functionPointers.find(name) == functionPointers.end() ) {
            cout << "No valid OPCODE" << endl;
            throw;
        } else {
            (*(functionPointers[name]))(iss);
        }
    }
    deleteVariables();
    readFile.close();
    return 0;
}