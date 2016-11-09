#include "common.h"
#include "VAR.h"
#include "STRING.h"
#include "templateVar.h"
#include "templateVar.cpp"
#include "helperFunctions.h"

map<string, VAR*> varMap = {
	{ "NUMERIC", new templateVar<int> },
	{ "REAL", new templateVar<double> },
	{ "CHAR", new templateVar<char> },
	{ "STRING", new STRING() },
};
// map<string, LABEL*> createdLabels;
map<string, VAR*> createdVariables;

void varHelper(stringstream& ss) {
	string str = "";
	getline(ss, str, ',');
    cout << str << endl;
	getline(ss >> ws, str, ',');
    cout << str << endl;
	VAR * obj = varMap[str];
    if( obj != NULL ) {
        ss >> ws;
        VAR * objTemp = obj;
        obj = obj -> clone(ss);
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
            if( obj == NULL ) {
                cout << "Variable does not exist" << endl;
                throw;
            } // do shit
		} else {
            // convert str to appropiate type
        }
    }
}

void setStrHelper( stringstream &ss ) {
	string str = "";
	getline(ss, str, ',');
	VAR * obj = createdVariables[str];
	if( obj == NULL ) {
		cout << "Variable " << str << " does not exit" << endl;
		throw;
	} else {
		int i;
		char a;
        getline(ss >> ws, str, ',');
	    i = stoi(str.c_str());
	    getline(ss >> ws, str, ',');
	    stringstream iss(str);
	    iss >> a;
	    obj -> setStringValue(a, i);
	    obj -> print();
	}
}

void getStrHelper( stringstream &ss ) {
    string str = "";
    getline(ss, str, ',');
    VAR * obj = createdVariables[str];
    if( obj == NULL ) {
    	cout << "Variable " << str << " does not exist" << endl;
    	throw;
    }
    getline(ss, str, ',');
	int x;
    char a;
    if( str.c_str()[0] == '$' ) {
    	x = obj -> getNumericValue();
    } else {
        x = stoi(str);
    }
    getline(ss, str, ',');
    VAR * newObj = createdVariables[str];
    if( newObj == NULL ) {
        cout << "Variable " << str << " does not exist" << endl;
    } else {
        a = obj -> getStringValue(x);
        newObj -> setStringValue(a, x);
        newObj -> print();
    }

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
	for(map<string, VAR*>::iterator itr = createdVariables.begin(); itr != createdVariables.end(); itr++) {
        cout << "Deleting Var: " << itr -> first << endl;
        delete( itr -> second );
        itr -> second = NULL;
    }
    for(map<string, VAR*>::iterator itr = varMap.begin(); itr != varMap.end(); itr++) {
        delete(itr -> second);
        itr -> second = NULL;
    }
    createdVariables.clear();
    varMap.clear();
}