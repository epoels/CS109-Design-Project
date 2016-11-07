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
        //Var* result;

public:
        Math_Funct(){cout << "Math_Funct made" << endl;}
        ~Math_Funct(){cout << "Math_Funct destroyed" << endl;}
        bool validator(){}
                //Var* result = var_convert(params[0]);
                //if(result!=null_ptr){continue;}
        void process(){}
};
class Add : Math_Funct{
protected:
        vector<string> params;
        //Var* result;
        vector<float> converted_params;

public:
        Add(vector<string> input) : params(input.begin()+1, input.end()-1){cout << "Add made" << endl;}
        ~Add(){cout << "Add destroyed" << endl;}
        bool validator(){
                //parameter counter
                int num_params=0;
                //check that first element of input is NUMERIC or REAL variable
                //Var* result = var_convert(input[0]);

                //convert paramter list
                for(string s : params){ 
                        try{
                                //if parameter is variable, pull from map
                                if(s[0]=='$'){num_params++; /*fetch matching var*->result();*/}
                                //if parameter is number, convert to float
                                else if(isdigit(s[0])){num_params++; converted_params.push_back(stof(s));}
                                //all other paramter types are invalid
                                else{return false;cout << "validator failed" << endl;}
                        }
                        catch(...){return false;cout << "validator failed" << endl; }
                        if(num_params>12){return false;}
                }

        }
        void process(){
                if(validator())
                cout << "processing..." << endl;
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
