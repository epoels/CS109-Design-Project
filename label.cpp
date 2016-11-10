#include"Label.h"
#include<sstream>
label::label() {} //default constructor
label::label(string x, int y) {
	linenumber = y + 1;
	name = x;
}//copy constructor

void label::initialize(stringstream &ss, int x) {
	string str = "";
	getline(ss, str, ' ');
	name = str;
	linenumber = x + 1;
	labelclass.insert(pair<string, int>(name, linenumber));
}
label::~label() { //destructor
}
label* label::clone(stringstream&ss, int x) {
	label* nlabel = new label();
	nlabel->initialize(ss, x);
	return nlabel;
}