
void  JMPZHelper(stringstream&ss) {
	string str = "";
	stringstream iss(ss.str());
	getline(ss, str, ' ');
	jumpz* A = new jumpz();
	if (A != NULL) {
		A->initialize(iss, counter);
		getline(iss, str, ',');
		getline(iss, str, ',');
		label * foundLabel = createdLabels[A->labelname];
		if (foundLabel == NULL) {
			cerr << "No label Found" << endl;
			exit(1);
		}
		else {
			if (str[0] == '$') {
				VAR * obj = createdVariables[str];
				if (obj == NULL) {
					cerr << "Variable does not exist" << endl;
					exit(1);
				}
				else {
					int i = obj->getNumericValue();
					if (i == 0) {
						counter = foundLabel->linenumber;
					}
				}
			}
			else {
				if (all_of(str.begin(), str.end(), isdigit)) {
					int i = stoi(str);
					if (i == 0) {
						counter = foundLabel->linenumber;
					}
				}
				else {
					cerr << "You cannot use double on JMP";
				}
			}
		}
		delete(A);
	}
}


void  JMPNZHelper(stringstream&ss) {
	string str = "";
	stringstream iss(ss.str());
	getline(ss, str, ' ');
	jumpnz* A = new jumpnz();
	if (A != NULL) {
		A->initialize(iss, counter);
		getline(iss, str, ',');
		getline(iss, str, ',');
		label * foundLabel = createdLabels[A->labelname];
		if (foundLabel == NULL) {
			cerr << "No label Found" << endl;
			exit(1);
		}
		else {
			if (str[0] == '$') {
				VAR * obj = createdVariables[str];
				if (obj == NULL) {
					cerr << "Variable does not exist" << endl;
					exit(1);
				}
				else {
					int i = obj->getNumericValue();
					if (i != 0) {
						counter = foundLabel->linenumber;
					}
				}
			}
			else {
				if (all_of(str.begin(), str.end(), isdigit)) {
					int i = stoi(str);
					if (i != 0) {
						counter = foundLabel->linenumber;
					}
				}
				else {
					cerr << "You cannot use double on JMP";
				}
			}
		}
		delete(A);
	}
}

void  JMPGTHelper(stringstream&ss) {
	string str = "";
	stringstream iss(ss.str());
	getline(ss, str, ' ');
	jumpgt* A = new jumpgt();
	string sto = "";
	if (A != NULL) {
		A->initialize(iss, counter);
		getline(iss, str, ',');
		getline(iss, str, ',');
		getline(iss, sto, ',');
		label * foundLabel = createdLabels[A->labelname];
		if (foundLabel == NULL) {
			cerr << "No label Found" << endl;
			exit(1);
		}
		else {
			if (str[0] == '$') {
				VAR * obj = createdVariables[str];
				if (obj == NULL) {
					cerr << "Variable does not exist" << endl;
					exit(1);
				}
				else {
					int i = obj->getNumericValue();
					if (sto[0] == '$') {
						VAR * obj2 = createdVariables[str];
						if (obj2 == NULL) {
							cerr << "Variable does not exist" << endl;
							exit(1);
						}
						else {
							int op = obj2->getNumericValue();
							if (i > op) {
								counter = foundLabel->linenumber;
							}
						}
					}
					else {
						if (all_of(sto.begin(), sto.end(), isdigit)) {
							int i2 = stoi(sto);
							if (i > i2) {
								counter = foundLabel->linenumber;
							}
						}
						else {
							cerr << "syntax error";
						}

					}
				}
			}

			else if (all_of(str.begin(), str.end(), isdigit)) {
				int i = stoi(str);
				if (sto[0] == '$') {
					VAR * obj2 = createdVariables[str];
					if (obj2 == NULL) {
						cerr << "Variable does not exist" << endl;
						exit(1);
					}
					else {
						int op = obj2->getNumericValue();
						if (i > op) {
							counter = foundLabel->linenumber;
						}
					}
				}
				else {
					if (all_of(sto.begin(), sto.end(), isdigit)) {
						int i2 = stoi(sto);
						if (i > i2) {
							counter = foundLabel->linenumber;
						}
					}
					else {
						cerr << "syntax error";
					}

				}
			}
			else {
				cerr << "syntax error";
			}
			delete(A);
		}
	}
}

void  JMPLTHelper(stringstream&ss) {
	string str = "";
	stringstream iss(ss.str());
	getline(ss, str, ' ');
	jumplt* A = new jumplt();
	string sto = "";
	if (A != NULL) {
		A->initialize(iss, counter);
		getline(iss, str, ',');
		getline(iss, str, ',');
		getline(iss, sto, ',');
		label * foundLabel = createdLabels[A->labelname];
		if (foundLabel == NULL) {
			cerr << "No label Found" << endl;
			exit(1);
		}
		else {
			if (str[0] == '$') {
				VAR * obj = createdVariables[str];
				if (obj == NULL) {
					cerr << "Variable does not exist" << endl;
					exit(1);
				}
				else {
					int i = obj->getNumericValue();
					if (sto[0] == '$') {
						VAR * obj2 = createdVariables[str];
						if (obj2 == NULL) {
							cerr << "Variable does not exist" << endl;
							exit(1);
						}
						else {
							int op = obj2->getNumericValue();
							if (i < op) {
								counter = foundLabel->linenumber;
							}
						}
					}
					else {
						if (all_of(sto.begin(), sto.end(), isdigit)) {
							int i2 = stoi(sto);
							if (i < i2) {
								counter = foundLabel->linenumber;
							}
						}
						else {
							cerr << "syntax error";
						}

					}
				}
			}

			else if (all_of(str.begin(), str.end(), isdigit)) {
				int i = stoi(str);
				if (sto[0] == '$') {
					VAR * obj2 = createdVariables[str];
					if (obj2 == NULL) {
						cerr << "Variable does not exist" << endl;
						exit(1);
					}
					else {
						int op = obj2->getNumericValue();
						if (i < op) {
							counter = foundLabel->linenumber;
						}
					}
				}
				else {
					if (all_of(sto.begin(), sto.end(), isdigit)) {
						int i2 = stoi(sto);
						if (i < i2) {
							counter = foundLabel->linenumber;
						}
					}
					else {
						cerr << "syntax error";
					}

				}
			}
			else {
				cerr << "syntax error";
			}
			delete(A);
		}
	}
}

void  JMPGTEHelper(stringstream&ss) {
	string str = "";
	stringstream iss(ss.str());
	getline(ss, str, ' ');
	jumpgte* A = new jumpgte();
	string sto = "";
	if (A != NULL) {
		A->initialize(iss, counter);
		getline(iss, str, ',');
		getline(iss, str, ',');
		getline(iss, sto, ',');
		label * foundLabel = createdLabels[A->labelname];
		if (foundLabel == NULL) {
			cerr << "No label Found" << endl;
			exit(1);
		}
		else {
			if (str[0] == '$') {
				VAR * obj = createdVariables[str];
				if (obj == NULL) {
					cerr << "Variable does not exist" << endl;
					exit(1);
				}
				else {
					int i = obj->getNumericValue();
					if (sto[0] == '$') {
						VAR * obj2 = createdVariables[str];
						if (obj2 == NULL) {
							cerr << "Variable does not exist" << endl;
							exit(1);
						}
						else {
							int op = obj2->getNumericValue();
							if (i >= op) {
								counter = foundLabel->linenumber;
							}
						}
					}
					else {
						if (all_of(sto.begin(), sto.end(), isdigit)) {
							int i2 = stoi(sto);
							if (i >= i2) {
								counter = foundLabel->linenumber;
							}
						}
						else {
							cerr << "syntax error";
						}

					}
				}
			}

			else if (all_of(str.begin(), str.end(), isdigit)) {
				int i = stoi(str);
				if (sto[0] == '$') {
					VAR * obj2 = createdVariables[str];
					if (obj2 == NULL) {
						cerr << "Variable does not exist" << endl;
						exit(1);
					}
					else {
						int op = obj2->getNumericValue();
						if (i >= op) {
							counter = foundLabel->linenumber;
						}
					}
				}
				else {
					if (all_of(sto.begin(), sto.end(), isdigit)) {
						int i2 = stoi(sto);
						if (i >= i2) {
							counter = foundLabel->linenumber;
						}
					}
					else {
						cerr << "syntax error";
					}

				}
			}
			else {
				cerr << "syntax error";
			}
			delete(A);
		}
	}
}

void  JMPLTEHelper(stringstream&ss) {
	string str = "";
	stringstream iss(ss.str());
	getline(ss, str, ' ');
	jumplte* A = new jumplte();
	string sto = "";
	if (A != NULL) {
		A->initialize(iss, counter);
		getline(iss, str, ',');
		getline(iss, str, ',');
		getline(iss, sto, ',');
		label * foundLabel = createdLabels[A->labelname];
		if (foundLabel == NULL) {
			cerr << "No label Found" << endl;
			exit(1);
		}
		else {
			if (str[0] == '$') {
				VAR * obj = createdVariables[str];
				if (obj == NULL) {
					cerr << "Variable does not exist" << endl;
					exit(1);
				}
				else {
					int i = obj->getNumericValue();
					if (sto[0] == '$') {
						VAR * obj2 = createdVariables[str];
						if (obj2 == NULL) {
							cerr << "Variable does not exist" << endl;
							exit(1);
						}
						else {
							int op = obj2->getNumericValue();
							if (i <= op) {
								counter = foundLabel->linenumber;
							}
						}
					}
					else {
						if (all_of(sto.begin(), sto.end(), isdigit)) {
							int i2 = stoi(sto);
							if (i <= i2) {
								counter = foundLabel->linenumber;
							}
						}
						else {
							cerr << "syntax error";
						}

					}
				}
			}

			else if (all_of(str.begin(), str.end(), isdigit)) {
				int i = stoi(str);
				if (sto[0] == '$') {
					VAR * obj2 = createdVariables[str];
					if (obj2 == NULL) {
						cerr << "Variable does not exist" << endl;
						exit(1);
					}
					else {
						int op = obj2->getNumericValue();
						if (i <= op) {
							counter = foundLabel->linenumber;
						}
					}
				}
				else {
					if (all_of(sto.begin(), sto.end(), isdigit)) {
						int i2 = stoi(sto);
						if (i <= i2) {
							counter = foundLabel->linenumber;
						}
					}
					else {
						cerr << "syntax error";
					}

				}
			}
			else {
				cerr << "syntax error";
			}
			delete(A);
		}
	}
}