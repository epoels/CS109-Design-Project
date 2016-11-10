#include"common.h"
using namespace std; 
class jumplte : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumplte();
	virtual ~jumplte();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	string labelname;
};