
#include"jump.h"
#include"common.h"

jumplte::jumplte() {}
jumplte::~jumplte() {}

void jumplte::clone(stringstream&ss, int x) {
	jumplte *ok = new jumplte();
	ok->initialize(ss, x);
}

void jumplte::initialize(stringstream &ss, int x) {
	linenumber = x;
	string str = "";
	getline(ss, str, ' ');
	labelname = str;
}
