#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<map>
#include"jumpnz.h"
#include"Headerfile.h"
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
	acjump();
}

void jumpnz::acjump() {
	string y = " ";
	getline(ss, y, ' ');
	map<string, *VAR>::iterator p;
	map<string, *label>::iterator q;
	p = createdVariable.find(y);
	q = createdLabels.find(A->labelname);
	if (isdigit(y)) {
		int ok = stoi(y);
		if (ok != 0) {
			if (p != createdLabels.end())
				counter = p->second->value;
			else if (p == createdLabels.end()) {
				cout << "label not found\n";
				exit(1);
			}
		}
	}
	else if (y[0] = '$') {
		if (q != createdVariable.end() && q->second->value != 0 && p != createdLabels.end())
			counter = p->second->value;
		else if (q != createdVariable.end() && q->second->value == 0 && p != createdLabels.end())
			counter = linenumber;
		else {
			cout << "label or variable not found\n";
			exit(1);
		}
	}
	else {
		cout << "syntax error\n";
		exit(1);
	}
}

