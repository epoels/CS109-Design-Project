#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
using namespace std; 
class jumpz : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumpz();
	string labelname;
	virtual ~jumpz();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	void acjump();
};

