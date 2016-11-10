#include "common.h"
using namespace std; 
class jumpgte : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumpgte();
	virtual ~jumpgte();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	string labelname;
};