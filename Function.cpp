#include "common.h"
#include "Var.h"
#include "templateVar.h"
#include "templateVar.cpp"
#include <string.h>

using namespace std;

//GLOBAL VARIABLES
map<string, VAR*> varMap;


class Function{
protected:      
        vector<string> params;

public:
        Function(){cout << "Function made" << endl;}
        ~Function(){cout << "Function destroyed" << endl;}
        //process to check parameters type and number
        virtual bool validator(){cout << "running BASE validator..." << endl;}
        //execute operation IFF validator()==true
        virtual void process(){cout << "BASE processing..." << endl;}
};
class Math : Function{
protected:
        vector<string> params;
        VAR* result;
        vector<float> converted_params;

public:
        Math(){cout << "Math made" << endl;}
        ~Math(){cout << "Math destroyed" << endl;}
        int convert(string s){
                //if parameter is variable
                if(s[0]=='$'){ return 1;}
                //if parameter is number
                else if(isdigit(s[0])){return 2; }
                //all other parameter types are invalid
                else {return 0;}
        }
        //check parameter number and types
        virtual bool validator(){}
        void process(){cout << "MATH processing..." << endl;}
};

class Add : Math{
protected:
        vector<string> params;
        VAR* result;
        vector<float> converted_params;
public:
        Add(vector<string> input) : result(varMap[input[0]]), params(input.begin()+1, input.end()){cout << "Add made" << endl;}
        ~Add(){cout << "Add destroyed" << endl;}
        //check that parameter number and types are valid
        bool validator(){
                cout << "running ADD validator..." << endl;
                //parameter counter
                int num_params=0;
                //check that result variable exists in variable map
                if(result==NULL){return false;}
                //convert parameter list
                for(string s : params){
                        try{
                                if(convert(s)!=0){
                                        num_params++;
                                        //if parameter is number, convert to float 
                                        if(convert(s)==2){converted_params.push_back(stof(s));}
                                        //if parameter is variable, pull value from variable map
                                        else if(convert(s)==1){converted_params.push_back(varMap[s]->getNumericValue());}
                                }
                                else{return false;}
                        }
                        catch(...){return false;}

                        if(num_params>12){return false;}
                }
                return true;
        }

        //if validator is true, run add process
        void process(){
                if(validator()){
                        cout << "ADD processing..." << endl;
                        //sum values
                        float sum = 0;
                        for(float f : converted_params){sum+=f;}
                        cout << sum << endl;
                        result->setNumValue(sum);
                }
                else{cout << "invalid parameter list" << endl;}

        }
};

class Mult : Math{
protected:
        vector<string> params;
        VAR* result;
        vector<float> converted_params;

public:
        Mult(vector<string> input) : result(varMap[input[0]]), params(input.begin()+1, input.end()){cout << "Mult made" << endl;}
        ~Mult(){cout << "Mult destroyed" << endl;}
        //check that parameter number and types are valid
        bool validator(){
                cout << "running MULT validator..." << endl;
                //parameter counter
                int num_params=0;
                //check that result is a variable that exists in the var map
                if(result==NULL){return false;}
                //convert parameter list
                for(string s : params){
                        try{
                                if(convert(s)!=0){
                                        num_params++;
                                        if(convert(s)==2){converted_params.push_back(stof(s));}
                                        else if(convert(s)==1){converted_params.push_back(varMap[s]->getNumericValue());}
                                }
                                else{return false;}
                        }
                        catch(...){return false;}

                        if(num_params>12){return false;}
                }
                return true;
        }
        //if validator is true, run add process
        void process(){
                if(validator()){
                        cout << "MULT processing..." << endl;
                        //sum values
                        float prod  = 1;
                        for(float f : converted_params){prod*=f;}
                        cout << prod << endl;
                        result->setNumValue(prod);
                }
                else{cout << "invalid parameter list" << endl;}

        }
};

int main(){

        VAR* obj = new templateVar<int>("$myInt", 2);
        obj->varInsert (varMap);
        VAR* obj2 = new templateVar<int>("$myInt2", 3);
        obj2->varInsert (varMap);
        vector<string> stuff;
        stringstream in("$myInt, 2, $myInt2, 4, 5");
        stuff.push_back ("$myInt");
        stuff.push_back ("2");
        stuff.push_back ("$myInt2");
        stuff.push_back ("4");
        stuff.push_back ("5");
        for(string s : stuff){cout << s << " ";}
        cout << endl;
        Add* add = new Add(stuff);
        add->process();
        Mult* mult = new Mult(stuff);
        mult->process();
        delete(mult);
        delete(add);
        cout << "variable: ";
        obj->print();
        delete(obj);
        delete(obj2);
}

