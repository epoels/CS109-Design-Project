#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<map>
using namespace std;

class jumproto { //declaration
protected:
private:
public:
	jumproto();
	virtual ~jumproto();
	virtual void initialize(stringstream &ss);
	virtual void acjump(stringstream&ss);
	virtual void clone(stringstream&ss, int x);
};