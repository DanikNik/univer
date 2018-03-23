#include <iostream>
#include <fstream>
using namespace std;

bool isin(int num, int * arr, int len){
    for(int i; i < len; i++){
        if(num == arr[i]){
            return 1;
        }
    }
    return 0;
}

int * append(int num, int * arr, int len){
    int * temp1 = new int [len+1];
    for (int i = 0; i < len; i++) {
        temp1[i] = arr[i];
    }
    temp1[len] = num;
    return temp1;
}

int * makeset(int * myarr, int len, int &setlen){
    int * temp;
    setlen = 0;
    for (size_t i = 0; i < len; i++) {
        if(isin(myarr[i], temp, setlen) == false){
            temp = append(myarr[i], temp, setlen);
            setlen++;
        }
    }
    return temp;
}

int main(int argc, char const *argv[]) {
    fstream myfile("data.txt", ios_base::in);
    int a;
    int len = 0;
    int * arr;
    while (myfile >> a){
        arr = append(a, arr, len);
        len++;
    }

    int setlen = 0;
    int * set = makeset(arr, len, setlen);

    int * counter = new int [setlen];
    for (size_t i = 0; i < setlen; i++) {
        counter[i] = 0;
    }
    for (size_t i = 0; i < len; i++) {
        for (size_t j = 0; j < setlen; j++) {
            if (set[j] == arr[i]){
                counter[j] ++;
            }
        }
    }

    for (size_t i = 0; i < setlen; i++) {
        cout << set[i] << " x" << counter[i] << endl;
    }

    return 0;
}
