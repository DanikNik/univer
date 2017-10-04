#include <iostream>
using namespace std;

int test(string b[], int size_arr) {
    for (int i = 0; i < size_arr; i++){
        cout << b[i][1] << endl;
        cout << b[i] << endl;
    }
    return 0;
}


int main(int argc, char const *argv[]) {
    /* code */
    string a[5] = {"11", "q2", "rt3", "mt4", "iu5"};
    int arr_len = sizeof(a)/sizeof(a[0]);
    test(a, arr_len);
    return 0;
}
