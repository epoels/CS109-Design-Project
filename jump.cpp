#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<map>
#include"jump.h"
using namespace std;

extern int counter;
extern map<string, int>labelclass;
extern map<string, int>variable;

jump::jump() {}
jump::~jump() {}


void jump::initialize(stringstream &ss, int x) {
	string str = "";
	getline(ss, str, ' ');
	string labelname = str;
	linenumber = x + 1;
	acjump(str);
}

void jump::acjump(string x) {
	map<string, int>::iterator p;
	p = labelclass.find(x);
	if (p != labelclass.end())
		counter = p->second;
	else {
		cout << "label not found\n";
		exit(1);
	}
}

void jump::clone(stringstream&ss, int x) {
	jump *ok = new jump();
	ok->initialize(ss, x);
}