#ifndef CLASS
#define CLASS

#include <iostream>
#include <cstring>
using namespace std;

static int COUNTER = 0;

class MyClass{
private:
    // int val1;
    // int val2;
    // char* name;

    void private_method(){
        cout << "I am private method\n";
    }
protected:
    void protected_method(){
        cout << "I am protected method\n";
    }
public:
    int val1;
    int val2;
    char* name;
    MyClass();
    MyClass(MyClass * instance);
    MyClass(int a, int b);
    MyClass(int a, int b, const char* n_name);
    MyClass(int a, int b, char* n_name);
    ~MyClass();

    void set_val1(int val);
    void set_val2(int val);
    void set_name(const char* n_name);
    void set_name(char* n_name);
    void get_info();

    void operator = (const MyClass& obj){
        return MyClass(obj.val1, obj.val2, obj.name);
    }
    friend ostream& operator << (ostream &os, MyClass &obj);
    friend istream& operator >> (istream &os, MyClass &obj);
    MyClass& operator + (int i);
    MyClass& operator - (int i);
    MyClass& operator + (MyClass& obj);
    MyClass& operator - (MyClass& obj);
    MyClass& operator + (MyClass& obj1, MyClass& obj2);
    MyClass& operator - (MyClass& obj1, MyClass& obj2);
    bool operator > (MyClass& obj);
    bool operator < (MyClass& obj);
    // MyClass& operator ++ ();
    // MyClass operator ++ (int);

};

class Inherited_Class : public MyClass{
public:
    Inherited_Class() : MyClass(){}
    Inherited_Class(int a, int b) : MyClass(a, b){}
    Inherited_Class(int a, int b, const char* n_name) : MyClass(a, b, n_name){}
    Inherited_Class(int a, int b, char* n_name) : MyClass(a, b, n_name){}
    void call_protected(){
        protected_method();
    }
};

#endif /* end of include guard: CLASS */
