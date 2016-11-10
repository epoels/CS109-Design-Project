#include "Function.h"

Function::Function(){cout << "Function made" << endl;}
Function::~Function(){cout << "Function destroyed" << endl;}
//process to check parameters type and number
bool Function::validator(){cout << "running BASE validator..." << endl;}
//execute operation IFF validator()==true
void Function::process(){cout << "BASE processing..." << endl;}
