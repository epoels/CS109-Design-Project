void  JMPHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jump* A = Var[str];
	if (A != NULL) {
		A = A->initialize(ss, counter);
		map<string, label*>::iterator p;
		p = labelclass.find(A->labelname);
		if (p != createdLabel.end())
			counter = p->second->linenumber;
		else {
			cout << "label not found\n";
			exit(1);
		}
	}
}

void  JMPZHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpz* A = Var[name];
	if (A != NULL) {
		A = A->initialize(ss, counter);
		delete(A);
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