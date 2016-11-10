#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<map>
#include"jump.h"
#include"Headerfile.h"

jumplte::jumplte() {}
jumplte::~jumplte() {}

void jumplte::clone(stringstream&ss, int x) {
	jumplte *ok = new jumplte();
	ok->initialize(ss, x);
}

void jumplte::initialize(stringstream &ss, int x) {
	linenumber = x;
	string str = "";
	string var = "";
	string var2 = "";
	getline(ss, str, ' ');
	getline(ss, var, ',');
	getline(ss, var2, ',');
	acjump(str, var, var2);
}

void jumplte::acjump(string x, string y, string z) {
	map<string, *VAR>::iterator q;
	map<string, *label>::iterator o;
	map<string, *VAR>::iterator p;
	o = createdLabels.find(x);
	q = createdVariables.find(y);
	p = createdVariables.find(z);

	if (y[0] == '$') {
		if (isdigit(z) && isdigit(q->second->value) {
			int i = stoi(z);
			if (i >= q->second->value &&o != createdLabels.end() && q != createdVariables.end())
				counter = o->second->linenumber;
			else if (i < q->second->value &&o != createdLabels.end() && q != createdVariable.end())
				counter = linenumber;
			else {
				cout << "label or variable not found\n";
				exit(1);
			}

		}
		else if (z[0] == '$') {
			if (isdigit(p->second->value)) {
				if (q->second->value <= p->second-> && o != createdLabels.end() && p != createdVariables.end() && q != createdVariables.end())
					counter = o->second->linenumber;
				else if (p->second->value < q->second->value &&o != createdLabels.end() && p != createdVariables.end() && q != createdVariable.end())
					counter = linenumber;
				else {
					cout << "label or variable not found\n";
					exit(1);
				}
			}
		}
	}
	else if (isdigit(y)) {
		int op = stoi(y);
		if (isdigit(z) && isdigit(q->second->value)) {
			int i = stoi(z);
			if (i >= op && o != createdLabels.end())
				counter = o->second->linenumber;
			else if (i < op &&o != createdLabels.end())
				counter = linenumber;
			else {
				cout << "label or variable not found\n";
				exit(1);
			}
		}
		else if (z[0] == '$') {
			if (isdigit(p->second->value)) {
				if (op <= p->second->value && o != createdLabels.end() && p != createdLabels.end())
					counter = o->second->linenumber;
				else if (p->second->value < op &&o != createdLabels.end() && p != createdLabels.end())
					counter = linenumber;
				else {
					cout << "label or variable not found\n";
					exit(1);
				}
			}
		}
	}
	else {
		cout << "syntax error\n";
		exit(1);
	}
}