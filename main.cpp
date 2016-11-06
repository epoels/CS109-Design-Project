#include "common.h"
#include "String.h"
#include "templateVar.h"
#include "Var.h"

// class VAR {
//     protected:
//     public:
//      VAR();
//         virtual void constructVar(stringstream &ss) = 0;
//         virtual void print() = 0;
//      virtual ~VAR();
// };

// VAR::VAR(){}

// VAR::~VAR(){}

// template<typename T>
// class templateVar: public VAR {
//     protected:
//         string name;
//         T value;
//     public:
//         templateVar();
//         templateVar(const string& inName, T val);
//         virtual void constructVar(stringstream &ss);
//         void print();
//         virtual~templateVar();
// };

// template<typename T>
// templateVar<T>::templateVar() {
//     cout << "Ok we are constructing an object" << endl;
//     name = "";
//     value = 0;
// }

// template<typename T>
// templateVar<T>::templateVar(const string& inName, T val) {
//     name = inName;
//     value = val;
//     cout << name << ", " << value << endl;
// }

// template<typename T>
// T convert(const string& s){
//     stringstream ss(s);
//     T temp;
//     ss >> temp;
//     return temp;
// }

// template<typename T>
// void templateVar<T>::constructVar(stringstream &ss) {
//     string str ="";
//     getline(ss,str,',');
//     name = str.c_str();
//     getline(ss,str,',');
//     value = convert<T>(str.c_str());
// }

// template<typename T>
// void templateVar<T>::print() {
//     cout << name << ", " << value << endl;
// }

// template<typename T>
// templateVar<T>::~templateVar(){}

// class STRING : public VAR {
//     protected:
//         string name;
//         int size;
//         char* value;
//     public:
//         STRING();
//         STRING(const string& inName, int inSize, char* inValue);
//         virtual void constructVar(stringstream &ss);
//         void print();
//         virtual ~STRING();
// };

// STRING::STRING(){
//     name = ""; 
//     size = 0; 
//     value = NULL;
// }

// STRING::STRING(const string& inName, int inSize, char * inValue) {
//     if( inSize > 256 || inSize < 0 || sizeof(inValue)/sizeof(*inValue) > 256 ) {
//         cout << "Char array size must not exceed 256" << endl;
//         throw;
//     }
//     name = inName;
//     size = inSize;
//     value = inValue;
// }

// void STRING::print() {
//     cout << name << ", "  << size << ", " << value << endl;
// }

// void STRING::constructVar(stringstream &ss) {
//     string str = "";
//     getline(ss, str, ',');
//     name = str.c_str();
//     getline(ss, str, ',');
//     size = stoi(str.c_str(), NULL);
//     getline(ss, str, ',');
//     value = (char*)str.c_str();
// }

// STRING::~STRING(){}
int main() {
    map<string, VAR*> varMap;
    varMap["NUMERIC"] = new templateVar<int>;
    // varMap["REAL"] = new templateVar<double>;
    // varMap["CHAR"] = new templateVar<char>;
    // varMap["STRING"] = new STRING();
    string line ="";
    ifstream readFile("ExampleFile.txt");
    string name ="";
    while(getline(readFile, line)) {
        stringstream iss(line); // Load line to the sting stream
        getline(iss, name, ',');
        VAR * obj = varMap[name];
        if( obj != NULL ) {
            obj -> constructVar(iss);
            obj -> print();
            delete(obj);
        }
    }
    readFile.close();
    return 0;
}