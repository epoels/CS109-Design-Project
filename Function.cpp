#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Base_Funct{
protected:
        vector<string> params;

public:
        Base_Funct(){cout << "Base_Funct made" << endl;}
        ~Base_Funct(){cout << "Base_Funct destroyed" << endl;}
        //process to check parameters type and number
        virtual bool validator(){};
        //execute operation IFF validator()==true
        virtual void process(){};
};

class Math_Funct : Base_Funct{
protected:
        vector<string> params;
        //VAR* result;
        vector<float> converted_params;

public:
        Math_Funct(){cout << "Math made" << endl;}
        ~Math_Funct(){cout << "Math_Funct destroyed" << endl;}
        //check parameter number and types
        virtual bool validator(){}
        void process(){cout << "MATH processing..." << endl;}
};
class Add : Math_Funct{
protected:
        vector<string> params;
        //VAR* result;
        vector<float> converted_params;
public:
        Add(vector<string> input) : params(input.begin()+1, input.end()){cout << "Add made" << endl;}
        ~Add(){cout << "Add destroyed" << endl;}
        //check that parameter number and types are valid
        bool validator(){
                cout << "running ADD validator..." << endl;
                //parameter counter
                int num_params=0;
                //pull variable from map
                //result = createdVariables[input[0]];
                //if(result==NULL){return false;}
                //convert parameter list
                for(string s : params){
                        cout << s << endl;
                        try{
                                //if parameter is variable, pull from map
                                if(s[0]=='$'){num_params++; /*converted_params.pushback(createdVariables[s]->getValue())*/}
                                //if parameter is number, convert to float
                                else if(isdigit(s[0])){num_params++; converted_params.push_back(stof(s));}
                                //all other parameter types are invalid
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
                        //result->setValue(sum);
                }
                else{cout << "invalid parameter list" << endl;}

        }
};
class Mult : Math_Funct{
protected:
        vector<string> params;
        //VAR* result;
        vector<float> converted_params;

public:
        Mult(vector<string> input) : params(input.begin()+1, input.end()){cout << "Mult made" << endl;}
        ~Mult(){cout << "Mult destroyed" << endl;}
        //check that parameter number and types are valid
        bool validator(){
                cout << "running MULT validator..." << endl;
                //parameter counter
                int num_params=0;
                //check that first element of input is NUMERIC or REAL variable
                //result = var_convert(input[0]);

                //convert parameter list
                for(string s : params){
                        cout << s << endl;
                        try{
                                //if parameter is variable, pull from map
                                if(s[0]=='$'){num_params++; /*fetch matching var*->result();*/}
                                //if parameter is number, convert to float
                                else if(isdigit(s[0])){num_params++; converted_params.push_back(stof(s));}
                                //all other paramter types are invalid
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
                        //result->setValue()=sum;
                }
                else{cout << "invalid paramater list" << endl;}

        }
};


int main(){
        vector<string> stuff;
        stuff.push_back ("one");
        stuff.push_back ("two");
        stuff.push_back ("three");
        stuff.push_back ("four");
        stuff.push_back ("fif");
        for(string s : stuff){cout << s << " ";}
        cout << endl;
        Add* math = new Add(stuff);
        math->process();
        delete(math);
}
