#ifndef CLASS
#define CLASS

#include <iostream>
#include <string.h>
using namespace std;
template<class T>
class Stack{
private:
    int length;
    T* data;
public:
    Stack(){
        this -> length = 0;
    }

    ~Stack(){
        delete [] this -> data;
    }

    void push(T a){
        if (length == 0){
            length = 1;
            this -> data = new T;
            this -> data[0] = a;
        }
        else{
            length += 1;
            T* temp = new T [length];
            for (int i = 0; i < length - 1; i++){
                temp[i] = this -> data[i];
            }
            temp[length-1] = a;
            delete [] this -> data;
            this -> data = new T [length];
            for (int i = 0; i < length; i++){
                this -> data[i] = temp[i];
            }
            delete [] temp;
        }
    }

    T pop(){
        length -= 1;
        T temp_data = data[length];
        T* temp = new T [length];
        for (int i = 0; i < length; i++){
            temp[i] = this -> data[i];
        }
        delete [] this -> data;
        this -> data = new T [length];
        for (int i = 0; i < length; i++){
            this -> data[i] = temp[i];
        }
        delete [] temp;
        return temp_data;
    }
};


#endif
