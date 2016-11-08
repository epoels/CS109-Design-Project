#include "common.h"
#include "VAR.h"
#include "STRING.h"
#include "templateVar.h"
#include "templateVar.cpp"

map<string, VAR*> createdVariables;
// varMap["NUMERIC"] = new templateVar<int>;
// varMap["REAL"] = new templateVar<double>;
// varMap["CHAR"] = new templateVar<char>;
// varMap["STRING"] = new STRING();

void varHelper(stringstream& ss) {
	string str = "";
	cout << ss.str() << endl;
	getline(ss, str, ',');
	cout << str.c_str() << endl;
	cout << varMap << endl;

	// VAR * obj = varMap[str];
 //        if( obj != NULL ) {
 //            ss >> ws;
 //            obj -> constructVar(ss);
 //            obj -> varInsert(createdVariables);
 //        }
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