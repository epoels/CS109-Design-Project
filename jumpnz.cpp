
#include"jumpnz.h"
using namespace std;
jumpnz::jumpnz() {}
jumpnz::~jumpnz() {}

void jumpnz::clone(stringstream&ss, int x) {
	jumpnz *ok = new jumpnz();
	ok->initialize(ss, x);
}

void jumpnz::initialize(stringstream &ss, int x) {
	linenumber = x;
	string str = "";
	getline(ss, str, ' ');
	labelname = str;
}


