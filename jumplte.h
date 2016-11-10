#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
using namespace std; 
class jumplte : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumplte();
	virtual ~jumplte();
	virtual void initialize(stringstream &ss, int x);
	void acjump(string x, string y, string z);
	int linenumber;
};