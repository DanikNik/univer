#include "class.h"

MyClass::MyClass(){
    cout << "[?] enter new instance's val1, val2 and name\n";
    this -> name = new char [15];
    cin >> this -> val1 >> this -> val2 >> this -> name;
}

MyClass::MyClass(int a, int b){
    this -> val1 = a;
    this -> val2 = b;
    cout << "[?] Enter new name for instance with val1 and val2 as "
        << this -> val1 <<' '<< this -> val2 << endl;
    char* buff = new char [15];
    this -> name = new char [15];
    cin >> buff;
    strcpy(this -> name, buff);
}

MyClass::MyClass(int a, int b, const char * n_name){
    this -> val1 = a;
    this -> val2 = b;
    this -> name = new char [15];
    strcpy(this -> name, n_name);
}

MyClass::MyClass(int a, int b, char * n_name){
    this -> val1 = a;
    this -> val2 = b;
    this -> name = new char [15];
    strcpy(this -> name, n_name);
}

MyClass::MyClass(MyClass * instance){
    this -> val1 = instance -> val1;
    this -> val2 = instance -> val2;
    this -> name = new char [15];
    strcpy(this -> name, instance -> name);
}

MyClass::~MyClass(){
    // cout << "deleting instance " << this -> name << endl;
    delete [] name;
}

void MyClass::set_val1(int val){
    this -> val1 = val;
}

void MyClass::set_val2(int val){
    this -> val2 = val;
}

void MyClass::set_name(const char* n_name){
    strcpy(this -> name, n_name);
}
void MyClass::set_name(char* n_name){
    strcpy(this -> name, n_name);
}
void MyClass::get_info(){
    cout <<"[] instance " << this -> name;
    cout << '\t' << val1 << ' ' << val2 << endl;
}

ostream& operator << (ostream &os, MyClass &obj){
    os << "[" << obj.name << "] " << obj.val1 << ' ' << obj.val2;
}

MyClass MyClass::operator + (int i){
    return MyClass(this -> val1 + i, this -> val2 + i, this -> name);
}

MyClass MyClass::operator - (int i){
    return MyClass(this -> val1 - i, this -> val2 - i, this -> name);
}

MyClass MyClass::operator + (MyClass& obj){
    return MyClass(this -> val1 + obj.val1, this -> val2 + obj.val2, this -> name);
}
MyClass MyClass::operator - (MyClass& obj){
    return MyClass(this -> val1 - obj.val1, this -> val2 - obj.val2, this -> name);
}
// MyClass MyClass::operator + (int obj1, MyClass& obj2){
    // return MyClass(obj2.val1 + i, obj2.val2 + i, obj2.name)
// }
// MyClass MyClass::operator - (int obj1, MyClass& obj2){
    // return MyClass(obj2.val1 - i, obj2.val2 - i, obj2.name)
// }
bool operator > (MyClass& obj1, MyClass& obj2){
    return obj1.val1 > obj2.val1;
}
bool operator < (MyClass& obj1, MyClass& obj2){
    return obj1.val1 < obj2.val1;
}
// MyClass& operator ++ (){
//     this -> val1++;
//     this -> val2++;
//     return *this;
// }
// MyClass operator ++ (int){
//     MyClass old = MyClass(*this);
//     this -> val1 --;
//     this -> val2 --;
//     return old;
// }
