#include "Sub.h"

//constructor
Sub::Sub(vector<string> input) : result_string(input[0]), params(input.begin()+1, input.end()){/*cout << "Sub made" << endl;*/}
//destructor
Sub::~Sub(){/*cout << "Sub destroyed" << endl;*/}

//check that parameter number and types are valid
bool Sub::validator(){
        //cout << "running SUB validator..." << endl;
        //parameter counter
        int num_params=0;
        //check that result is a variable that exists in the var map
        if(createdVariables.find(result_string)==createdVariables.end()){cerr << "IN SUB: the variable " << result_string << " does not exist" << endl; return false;}
        //convert parameter list
        for(string s : params){
                try{
                        if(convert(s)!=0){
                                num_params++;
                                if(convert(s)==2){converted_params.push_back(stof(s));}
                                else if(convert(s)==1){converted_params.push_back(createdVariables[s]->getNumericValue());}
                        }
                        else{cerr << "IN SUB: bad convert of " << s << endl; return false;}
                }
                catch(...){return false;}

                if(num_params!=2){cerr << "IN SUB: wrong number of parameters" << endl; return false;}
        }
        return true;
}

//if validator is true, run add process
void Sub::process(){
        if(validator()){
                //cout << "SUB processing..." << endl;
                //take the difference
                float diff = converted_params[0] - converted_params[1];
                cout << "Variable before SUB: ";
                createdVariables[result_string]->print();

                createdVariables[result_string]->setNumValue(diff);
                cout << "Variable after SUB: ";
                createdVariables[result_string]->print();
        }
        else{cerr << "IN SUB: invalid parameter list" << endl;}

}
