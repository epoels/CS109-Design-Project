#include "common.h"
#include "VAR.h"
#include "STRING.h"
#include "templateVar.h"
#include "templateVar.cpp"

void varHelper(stringstream& ss) {
	string str = "";
	cout << ss.str() << endl;
	getline(ss, str, ',');
	cout << str.c_str() << endl;
	// VAR * obj = varMap[str];
 //        if( obj != NULL ) {
 //            iss >> ws;
 //            obj -> constructVar(iss);
 //            obj -> varInsert(createdVariables);
 //        }
}

// void addHelper(stringstream& ss){
// 	cout << ss.str() << endl;
// }