#include "common.h"
#include "Var.h"
#include "String.h"
#include "templateVar.h"
#include "templateVar.cpp"
#include "helperFunctions.h"
#include "Function.h"
#include "Function.cpp"

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

void addHelper(stringstream& ss){
        cout << ss.str() << endl;
        vector<string> input;
        string in;
        ss >> ws;
        getline(ss, in, ' ');
        ss >> ws;
        while(getline(ss, in, ',')){ss >> ws; input.push_back(in);}
        Add* add = new Add(input);
        add->process();
        delete(add);
}

void multHelper(stringstream& ss){
        cout << ss.str() << endl;
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

void subHelper(stringstream& ss){
        cout << ss.str() << endl;
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

void divHelper(stringstream& ss){
        cout << ss.str() << endl;
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

void outHelper(stringstream& ss){
        cout << ss.str() << endl;
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
