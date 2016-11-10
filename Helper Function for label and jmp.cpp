

void  JMPZHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpz* A = Varmap[str];
	if (A != NULL) {
		A->initialize(ss, counter);
	}
	string y = " ";
	getline(ss, y, ' ');
	map<string, *VAR>::iterator p;
	map<string, *label>::iterator q;
	p = createdVariable.find(y);
	q = createdLabels.find(A->labelname);
	if (isdigit(y)) {
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
			if (q != createdVariable.end() && q->second->value == 0 && p != createdLabels.end())
				counter = p->second->value;
			else if (q != createdVariable.end() && q->second->value != 0 && p != createdLabels.end())
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
	jumpz* A = Varmap[str];
	if (A != NULL) {
		A->initialize(ss, counter);
	}

	string x = " ";
	getline(ss, x, ' ');
	string y = " ";
	getline(ss, y, ' ');

	map<string, int>::iterator q;
	map<string, int>::iterator p;
	p = labelclass.find(x);
	if (isdigit(y[0])) {
		float ok = stof(y);
		if (ok != 0) {
			if (p != labelclass.end())
				counter = p->second;
			else {
				cout << "label not found\n";
				exit(1);
			}
		}
		else
			counter = linenumber;
	}
	else if (y[0] == '$') {
		if (q != labelclass.end() && q->second != 0 && p != labelclass.end())
			counter = p->second;
		else if (q != labelclass.end() && q->second == 0 && p != labelclass.end())
			counter = linenumber;
		else {
			cout << "label not found\n";
			exit(1);
		}
	}
	else {
		cout << "syntax error\n";
		exit(1);
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