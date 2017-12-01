#include <iostream>
using namespace std;

char * add_mem(char *myset){
    int len = sizeof(myset)/sizeof(myset[0]);
    char *temp = new char [len+1];
    if (len != 0){
        for (size_t i = 0; i < len; i++) {
            temp[i] = myset[i];
        }
    }
    delete myset;
    return temp;
}

int main(int argc, char const *argv[]) {
    char *myset;
    for (int i = 0; i < 10; i++) {
        cout << "1";
        myset = add_mem(myset);
        myset[i] = (char)i;
    }
}
