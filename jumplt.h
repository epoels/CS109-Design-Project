#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
using namespace std; 
class jumplt : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumplt();
	virtual ~jumplt();
	virtual void initialize(stringstream &ss, int x);
	void acjump(string x, string y, string z);
	int linenumber;
};
