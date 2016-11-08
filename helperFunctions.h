#include "common.h"
#include "Var.h"
extern map<string, VAR*> varMap;

void varHelper( stringstream &ss );
void addHelper( stringstream &ss );
void subHelper( stringstream &ss );
void mulHelper( stringstream &ss );
void divHelper( stringstream &ss );
void assignHelper( stringstream &ss );
void outHelper( stringstream &ss );
void setStrHelper( stringstream &ss );
void getStrHelper( stringstream &ss );
void labelHelper( stringstream &ss );
void jmpHelper( stringstream &ss );
void jmpZHelper( stringstream &ss );
void jmpNZHelper( stringstream &ss );
void jmpGTHelper( stringstream &ss );
void jmpGTEHelper( stringstream &ss );
void jmpLTHelper( stringstream &ss );
void jmpLTEHelper( stringstream &ss );
void sleepHelper( stringstream &ss );
void deleteVariables();