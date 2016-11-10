#include "Div.h"

//constructor
Div::Div(vector<string> input) : result_string(input[0]), params(input.begin()+1, input.end()){/*cout << "Div made" << endl;*/}
//destructor
Div::~Div(){/*cout << "Div destroyed" << endl;*/}

//check that parameter number and types are valid
bool Div::validator(){
        //cout << "running DIV validator..." << endl;
        //parameter counter
        int num_params=0;
        //check that result is a variable that exists in the var map
        if(createdVariables.find(result_string)==createdVariables.end()){cerr << "IN DIV: the variable " << result_string << " does not exist" << endl; return false;}
        //convert parameter list
        for(string s : params){
                if(convert(s)!=0){
                        num_params++;
                        if(convert(s)==2){converted_params.push_back(stof(s));}
                        else if(convert(s)==1){converted_params.push_back(createdVariables[s]->getNumericValue());}
                }
                else{cerr << "IN DIV: bad convert of " << s << endl; return false;}
           
                if(converted_params[1]==0){cerr << "IN DIV: cannot divide by zero!" << endl; return false;}
                
        }
        if(num_params!=2){cerr << "IN DIV: wrong number of parameters" << endl; return false;}
        return true;
}
//if validator is true, run add process
void Div::process(){
        if(validator()){
                //cout << "DIV processing..." << endl;
                //take the quotient
                float num = converted_params[0];
                float den = converted_params[1];
                float quot = num / den;
                cout << "Variable before DIV: ";
                createdVariables[result_string]->print();

                createdVariables[result_string]->setNumValue(quot);

                cout << "Variable after DIV: ";
                createdVariables[result_string]->print();
        }
        else{cout << "invalid parameter list" << endl;}

}
