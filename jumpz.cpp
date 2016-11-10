
#include"jumpz.h"
using namespace std;
jumpz::jumpz() {}
jumpz::~jumpz() {}

void jumpz::clone(stringstream&ss, int x) {
	jumpz *ok = new jumpz();
	ok->initialize(ss, x);
}

void jumpz::initialize(stringstream &ss, int x) {
	linenumber = x;
	string str = "";
	getline(ss, str, ' ');
	labelname = str;

}

