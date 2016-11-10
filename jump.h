#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
#include"jumproto.h"
using namespace std; 

class jump : public jumproto {
public:
	jump();
	int linenumber;
	virtual ~jump();
	void initialize(stringstream &ss, int x);
	void acjump(string x);
	void clone(stringstream&ss, int x);
};


