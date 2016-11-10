#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
int counter;
map<string, int>labelclass;
map<string, int>variable;
map<int, string> myMap;

class label { //declaration
protected:
private:
public:
	label();
	label(string x, int y);
	~label();
	void initialize(stringstream &ss, int x);
	label* clone(stringstream&ss, int x);
	int linenumber;
	string name;
}; 
