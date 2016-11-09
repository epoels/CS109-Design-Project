#include "common.h"
#include "Var.h"
#include "String.h"
#include "templateVar.h"
#include "templateVar.cpp"
#include "helperFunctions.h"

typedef void(*ScriptFunction)(stringstream& ss);
map<string, ScriptFunction> functionPointers;
map<int, string> lines;

int main() {
    functionPointers["VAR"] = &varHelper;
    // functionPointers["ADD"]
    // functionPointers["SUB"]
    // functionPointers["MUL"]
    // functionPointers["DIV"]
    //functionPointers["ASSIGN"] = &assignHelper;
    // functionPointers["OUT"]
    functionPointers["SET_STR_CHAR"] = &setStrHelper;
    functionPointers["GET_STR_CHAR"] = &getStrHelper;
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
    int lineNumber = 0;
    // Loop through file filling a map 
    while(getline(readFile, line)) {
        if ( lineNumber >= 255) {
            cout << "Program is too large to continue ... exiting at line " << lineNumber << endl;
        }
        lines[lineNumber] = line;
        lineNumber++;
    }

    // We now create labels


    // Loop throught the line map and parse our OP code
    // Then we send it off to a helper function
    for(int i = 0; i <= lines.size()-1; i++ ){
        string fileLine = lines[i];
        stringstream iss(fileLine);// Load line to the string stream
        getline(iss, name, ' ');
        if( functionPointers.find(name) == functionPointers.end() ) {
            cout << "Input line is invalid: " << name << endl;
            cout << "No valid OPCODE" << endl;
            throw;
        } else {
            (*(functionPointers[name]))(iss);
        }
    }
    deleteVariables();
    functionPointers.clear();
    lines.clear();
    readFile.close();
    return 0;
}