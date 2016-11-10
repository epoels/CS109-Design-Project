#include "Mult.h"

//MULT CLASS MEMBER IMPLEMENTATION 
//constructor 
Mult::Mult(vector<string> input) : result_string(input[0]), params(input.begin()+1, input.end()){/*cout << "Mult made" << endl;*/}
//destructor
Mult::~Mult(){/*cout << "Mult destroyed" << endl;*/}

//check parameter list is valid
bool Mult::validator(){
        //cout << "running MULT validator..." << endl; 
        //parameter counter 
        int num_params=0;
        //check that result is a variable that exists in the var map 
        if(createdVariables.find(result_string)==createdVariables.end()){cerr << "IN MUL: the variable " << result_string << " does not exist" << endl; return false;}
        //convert parameter list 
        for(string s : params){
                try{
                        //if conversion was passed
                        if(convert(s)!=0){
                                num_params++;
                                //numeric value parameter
                                if(convert(s)==2){converted_params.push_back(stof(s));}
                                //variable parameter
                                else if(convert(s)==1){converted_params.push_back(createdVariables[s]->getNumericValue());}
                        }
                        else{cerr << "IN MUL: bad convert of " << s << endl; return false;}
                }
                catch(...){return false;}

                if(num_params<2 || num_params>12){cerr << "IN MUL: wrong number of parameters" << endl; return false;}
        }
        return true;
}
//if validator is true, run add process 
void Mult::process(){
        if(validator()){
                //cout << "MUL processing..." << endl; 
                //sum values 
                float prod  = 1;
                //multiply converted parameters together 
                for(float f : converted_params){prod*=f;}
                cout << "Variable before MUL: ";
                createdVariables[result_string]->print();

                //set value of first variable to the product
                createdVariables[result_string]->setNumValue(prod);
                cout << "Variable after MUL: ";
                createdVariables[result_string]->print();
        }
        else{cout << "IN MUL: invalid parameter list" << endl;}

}
