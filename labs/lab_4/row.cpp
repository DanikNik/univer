#include <iostream>
#include <math.h>
using namespace std;
double formula(int n){
    return pow(((pow(n,2) + 2)/(pow(n,2) + 3)), pow(n,1.5));
}

int main(){
    int k;
    double T = 0.000001;
    double sum = 0;
    for (int n = 1; n < 10 ; n++){
        sum+= formula(n);
    }
    cout << sum << endl;
}
