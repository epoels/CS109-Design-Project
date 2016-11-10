

void  JMPZHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpz* A = Varmap[str];
	if (A != NULL) {
		A->initialize(ss, counter);
	}
	delete(A);
}

void  JMPNZHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpz* A = Varmap[str];
	if (A != NULL) {
		A->initialize(ss, counter);
	}
	delete(A);
}

void  JMPGTHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpgt* A = Var[str];
	if (A != NULL) {
		A = A->initialize(ss, counter);
	}
	delete(A);
}

void  JMPLTHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumplt* A = Var[str];
	if (A != NULL) {
		A = A->initialize(ss, counter);
	}
	delete(A);
}

void  JMPGTEHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumpgte* A = Var[str];
	if (A != NULL) {
		A = A->initialize(ss, counter);
	}
	delete(A);
}

void  JMPLTEHelper(stringstream&ss) {
	string str = "";
	getline(ss, str, ' ');
	jumplte* A = Var[str];
	if (A != NULL) {
		A = A->initialize(ss, counter);
	}
	delete(A);
}