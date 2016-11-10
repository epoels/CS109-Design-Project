#include"common.h"
using namespace std; 
class jumpgt : public jumproto {
public:
	void clone(stringstream&ss, int x);
	jumpgt();
	virtual ~jumpgt();
	virtual void initialize(stringstream &ss, int x);
	int linenumber;
	string labelname;
};
