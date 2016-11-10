

void  JMPZHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpz* A = Varmap[name];
	if (A != NULL) {
		A->initialize(ss, counter);
	}
	string y = " ";
	getline(ss, y, ' ');
	map<string, *VAR>::iterator p;
	map<string, *VAR>::iterator q;
	p = labelclass.find(y);
	if (isdigit(y->second->value)) {
		int ok = stoi(y);
		if (ok == 0) {
			if (p != createdLabels.end())
				counter = p->second->value;
			else if (p == createdLabels.end()) {
				cout << "label not found\n";
				exit(1);
			}
		}
		else if (y[0] = '$') {
			q = createdVariables.find(y);
			if (q != variable.end() && q->second->value == 0 && p != createdLabels.end())
				counter = p->second->value;
			else if (q != variable.end() && q->second != 0 && p != labelclass.end())
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
}


void  JMPNZHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpnz* A = Var[name];
	if (A != NULL) {
		A = A->initialize(ss, counter);
		delete(A);
	}
}

void  JMPGTHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpgt* A = Var[name];
	if (A != NULL) {
		A = A->initialize(ss, counter);
		delete(A);
	}
}

void  JMPLTHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumplt* A = Var[name];
	if (A != NULL) {
		A = A->initialize(ss, counter);
		delete(A);
	}
}

void  JMPGTEHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpgte* A = Var[name];
	if (A != NULL) {
		A = A->initialize(ss, counter);
		delete(A);
	}
}

void  JMPLTEHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumplte* A = Var[name];
	if (A != NULL) {
		A = A->initialize(ss, counter);
		delete(A);
	}
}