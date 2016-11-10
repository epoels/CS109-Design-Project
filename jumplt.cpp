
#include"jumplt.h"
#include"common.h"
using namespace std;
jumplt::jumplt() {}
jumplt::~jumplt() {}

void jumplt::clone(stringstream&ss, int x) {
	jumplt *ok = new jumplt();
	ok->initialize(ss, x);
}

void jumplt::initialize(stringstream &ss, int x) {
	linenumber = x;
	string str = "";
	getline(ss, str, ' ');
	labelname = str;
}
