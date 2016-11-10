#include "common.h"
#include "Var.h"
#include "String.h"
#include "templateVar.h"
#include "templateVar.cpp"
#include "helperFunctions.h"
#include "Out.h"
#include "Add.h"
#include "Mult.h"
#include "Sub.h"
#include "Div.h"

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
        getline(ss, str, ',');
        getline(ss>>ws, str, ',');
        VAR * obj = varMap[str];
        if( obj != NULL ) {
            ss >> ws;
            VAR* objTemp = obj;
            obj = obj -> clone(ss);
            obj -> varInsert(createdVariables);
            obj -> print();
        }
}

void addHelper(stringstream& ss_in){
        stringstream ss(ss_in.str());
        vector<string> input;
        string in;
        ss >> ws;
        getline(ss, in, ' ');
        ss >> ws;
        while  (getline(ss, in, ',')) {ss>>ws; input.push_back(in);}
        Add* add = new Add(input);
        add->process();
        delete(add);
}
void multHelper(stringstream& ss_in){
        stringstream ss(ss_in.str());
        vector<string> input;
        string in;
        ss >> ws;
        getline(ss, in, ' ');
        ss >> ws;
        while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
        Mult* mult = new Mult(input);
        mult->process();
        delete(mult);
}

void subHelper(stringstream& ss_in){
        stringstream ss(ss_in.str());
        vector<string> input;
        string in;
        ss >> ws;
        getline(ss, in, ' ');
        ss >> ws;
        while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
        Sub* sub = new Sub(input);
        sub->process();
        delete(sub);
}

void divHelper(stringstream& ss_in){
        stringstream ss(ss_in.str());
        vector<string> input;
        string in;
        ss >> ws;
        getline(ss, in, ' ');
        ss >> ws;
        while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
        Div* div = new Div(input);
        div->process();
        delete(div);
}
void outHelper(stringstream& ss_in){
        stringstream ss(ss_in.str());
        vector<string> input;
        string in;
        ss >> ws;
        getline(ss, in, ' ');
        ss >> ws;
        while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
        Out* out = new Out(input);
        out->process();
        delete(out);
}

/*void sleepHelper(stringstream &ss) {
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
}*/

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
