#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
using namespace std; 
class jumpnz : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumpnz();
	virtual ~jumpnz();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	string labelname;
	void acjump();
};

