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
	getline(ss >> ws, str, ',');
	cout << str << endl;
	VAR * obj = varMap[str];
        if( obj != NULL ) {
            ss >> ws;
            // cout << ss.str() << endl;
            obj -> constructVar(ss);
            obj -> varInsert(createdVariables);
            obj -> print();
        }
}

void assignHelper( stringstream &ss ) {
    string str = ss.str();
    stringstream iss(str);
    string in = "";
    getline(iss, in, ' ');
    iss >> ws;
    getline(iss, in, ',');
    in = in.c_str();
    VAR * obj = createdVariables[in];
    if( obj == NULL ) {
    	cout << "Variable "<< in << " does not exist" << endl;
    	throw;
    } else {
    	getline(iss >> ws, in, ',');
    	if( in.c_str()[0] == '$' ) {
		    VAR * obj = createdVariables[str.c_str()];
		}
    }
}

void setStrHelper( stringstream &ss ) {
	string str = "";
	getline(ss, str, ',');
	VAR * obj = createdVariables[str.c_str()];
	if( obj == NULL ) {
		cout << "Variable " << str.c_str() << " does not exit" << endl;
		throw;
	} else {
		int i;
		char a;
        getline(ss >> ws, str, ',');
	    i = stoi(str.c_str());
	    getline(ss >> ws, str, ',');
	    a = str.c_str();
	    cout << a << endl;
	}
}

void getStrHelper( stringstream &ss ) {

}

void sleepHelper(stringstream &ss) {
	string str = "";
	getline(ss, str, ' ');
	getline(ss, str, ',');
	long long x;
	if( str.c_str()[0] == '$' ) {
		VAR * obj = createdVariables[str.c_str()];
		if( obj == NULL ) {
			cout << "The variable: " << str.c_str() << " does not exist" << endl;
			throw;
		} else {
			x = obj -> getNumericValue();
    	    cout << "Waiting " << x << " seconds" << endl;
			std::chrono::seconds dura( x);
    	    std::this_thread::sleep_for( dura );
    	    cout << "Done!" << endl;
		}
	} else {
		stringstream iss(str.c_str());
		iss >> x;
	    if( iss.fail() ) {
            cout << "Parameter does not match required type REAL or NUMERIC" << endl;
            iss.clear();
            throw;
        } else {
    	    cout << "Waiting " << x << " seconds" << endl;
    	    std::chrono::seconds dura(x);
    	    std::this_thread::sleep_for( dura );
    	    cout << "Done!" << endl;
        }
	}
}

void deleteVariables() {
	for( const auto &p : createdVariables ) {
        delete(p.second);
    }
}