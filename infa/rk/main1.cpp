#include <iostream>
#include <string.h>
using namespace std;

class MyString{
private:
    char* data;
    int size;
public:
    MyString(){
        this -> size = 0;
        this -> data = NULL;
    }
    MyString(const char* a){
        this -> size = strlen(a);
        this -> data = new char [this -> size];
        strcpy(this -> data, a);
    }
    MyString(char* a){
        this -> size = strlen(a);
        this -> data = new char [this -> size];
        strcpy(this -> data, a);
    }
    char* get_data(){
        return this -> data;
    }
    int get_size(){
        return this -> size;
    }
    void set(const char* a){
        this -> size = strlen(a);
        this -> data = new char [this -> size];
        strcpy(this -> data, a);
    }
    void set(char* a){
        this -> size = strlen(a);
        this -> data = new char [this -> size];
        strcpy(this -> data, a);
    }
    void concat(char * a){
        this -> size += strlen(a);
        strcat(this -> data, a);
    }
    void concat(const char * a){
        this -> size += strlen(a);
        strcat(this -> data, a);
    }
    void concat(MyString a){
        this -> size += a.get_size();
        strcat(this -> data, a.get_data()) ;
    }
    int find(const char * a){
        char * pointer =  strstr(this -> data, a);
        return (pointer - this -> data);
    }
    void print(){
        cout << this -> data << ' ' << this -> size << endl;
    }
    ~MyString(){
        delete[] this -> data;
    }
};


int main(){
    MyString a = MyString();
    a.set("abcd");
    a.print();

    MyString b = MyString("ghrt");
    b.print();

    a.concat("ef");
    a.print();

    a.concat(b);
    a.print();

    cout << a.find("ef") << endl;
}
