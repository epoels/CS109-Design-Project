#include "common.h"
#include "VAR.h"
#include "STRING.h"
#include "templateVar.h"
#include "templateVar.cpp"
#include "helperFunctions.h"

map<string, VAR*> createdVariables;
// map<string, LABEL*> createdLabels;
map<string, VAR*> varMap = {
	{ "NUMERIC", new templateVar<int> },
	{ "REAL", new templateVar<double> },
	{ "CHAR", new templateVar<char> },
	{ "STRING", new STRING() }
};

void varHelper(stringstream& ss) {
	string str = "";
	cout << ss.str() << endl;
	getline(ss, str, ',');
	VAR * obj = varMap[str];
        if( obj != NULL ) {
            ss >> ws;
            obj -> constructVar(ss);
            obj -> varInsert(createdVariables);
            obj -> print();
        }
}

// void addHelper(stringstream& ss){
// 	cout << ss.str() << endl;
// }

void sleepHelper(stringstream &ss) {
	string str = "";
	getline(ss, str, ',');
	getline(ss, str, ',');
	int x;
	ss >> x;
	if( ss.fail() ) {
        cout << "Parameter is not type int" << endl;
        ss.clear();
        throw;
    } else {
    	std::chrono::seconds dura( x);
    	std::this_thread::sleep_for( dura );
    	cout << "Waited " << x << " seconds" << endl;
    }
}

void deleteVariables() {
	for( const auto &p : createdVariables ) {
        delete(p.second);
    }
}