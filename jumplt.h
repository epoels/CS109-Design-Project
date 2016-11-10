#include "common.h"
using namespace std; 
class jumplt : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumplt();
	virtual ~jumplt();
	virtual void initialize(stringstream &ss, int x);
	string labelname;
	int linenumber;
};
