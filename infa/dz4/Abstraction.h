//
// Created by daniknik on 13.05.18.
//

#ifndef DZ4_ABSTRACTION_H
#define DZ4_ABSTRACTION_H

#include <iostream>
using namespace std;

class AbstractUnit {
protected:
    char* signature;
public:
    virtual void show() =0;
};

class IntArrUnit: public AbstractUnit{
private:
    int* data;
public:
    IntArrUnit(){
        this -> signature = new char [8];
        cin >> this -> signature;
        this -> data = new int [5];
        for (int i = 0; i < 5; ++i) {
            cin >> this -> data[i];
        }
    }
    ~IntArrUnit() {
        cout << "[+] IntArrUnit destructor\n";
        delete [] this -> signature;
        delete [] this -> data;
    }

    void show(){
        for (int i = 0; i < 5; ++i) {
            cout << this -> data[i] << ' ';
        }
        cout << '\n';
    }
};

class FloatUnit: public AbstractUnit{
private:
    float* data;
public:
    FloatUnit(){
        this -> signature = new char [8];
        cin >> this -> signature;
        this -> data = new float;
        cin >> *(this -> data);
    }
    ~FloatUnit() {
        cout << "[+] FloatUnit destructor\n";
        delete [] this -> signature;
        delete this -> data;
    }
    void show(){
        cout << *(this -> data);
        cout << '\n';
    }
};

#endif //DZ4_ABSTRACTION_H
