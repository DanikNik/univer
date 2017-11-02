#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;

double formula(int n){
    double x = sqrt(n);
    return pow((1 - 1/(x + 3)), x*x*x);
}

int main(){
    int k1 = 7, k2 = 12, k3 = 34;
    double T = 1e-10;
    double sum = 0.0;
    int n = 0;

    double s=1.0;
    cout << "[1] WHILE LOOP" << endl;
    while (s >= T){
        n++;
        s = formula(n);
        sum+=s;
        if(n == k1 or n == k2 or n == k3){cout<<setprecision(15) << "{+} sum for " << n << ": " << sum <<"\n  Last added element: " << s << endl;}
    }
    cout <<setprecision(15)<< "{+} sum for " << n << ": " << sum <<"\n  Last added element: " << s << endl;
    cout << endl;

    sum = 0.0;
    s = 1.0;
    cout << "[2] FOR LOOP" << endl;
    for(n=1; s >= T; n++){
        s = formula(n);
        sum+=s;
        if(n == k1 or n == k2 or n == k3){cout<<setprecision(15) << "{+} sum for " << n << ": " << sum <<"\n  Last added element: " << s << endl;}
    }
    cout<<setprecision(15) << "{+} sum for " << n << ": " << sum <<"\n  Last added element: " << s << endl;
    cout << endl;

    n = 0;
    sum = 0.0;
    cout << "[3] DO WHILE LOOP" << endl;
    do {
        n++;
        s = formula(n);
        sum+=s;
        if(n == k1 or n == k2 or n == k3){cout<<setprecision(15) << "{+} sum for " << n << ": " << sum <<"\n  Last added element: " << s << endl;}
    } while(s >= T);
    cout<<setprecision(15) << "{+} sum for " << n << ": " << sum <<"\n  Last added element: " << s << endl;
}
