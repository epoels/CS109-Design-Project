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
    // functionPointers["ADD"]
    // functionPointers["SUB"]
    // functionPointers["MUL"]
    // functionPointers["DIV"]
    functionPointers["ASSIGN"] = &assignHelper;
    // functionPointers["OUT"]
    functionPointers["SET_STR_CHAR"] = &setStrHelper;
    // functionPointers["GET_STR_CHAR"]
    // functionPointers["LABEL"]
    // functionPointers["JMP"]
    // functionPointers["JMPZ"]
    // functionPointers["JMPNZ"]
    // functionPointers["JMPGT"]
    // functionPointers["JMPGTE"]
    // functionPointers["JMPLT"]
    // functionPointers["JMPLTE"]
    functionPointers["SLEEP"] = &sleepHelper;
    string line ="";
    ifstream readFile("ExampleFile.txt");
    string name ="";
    while(getline(readFile, line)) {
        stringstream iss(line);// Load line to the string stream
        getline(iss, name, ' ');
        if( functionPointers.find(name) == functionPointers.end() ) {
            cout << "Input line is invalid: " << name << endl;
            cout << "No valid OPCODE" << endl;
            throw;
        } else {
            cout << name << endl;
            (*(functionPointers[name]))(iss);
        }
    }
    deleteVariables();
    readFile.close();
    return 0;
}