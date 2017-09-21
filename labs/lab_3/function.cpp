#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double function(double x){
    double y = 1 + x + pow(x,2)/2 + pow(x,3)/6 + pow(x,4)/24 + pow(x,5)/120 + pow(x,6)/720 + pow(x,7)/5040 - exp(x);
    return y;
}

int main(){
    double xn = -6, xk = -4, dx=0.1;
    int k = floor((xk - xn)/dx);
    double x_array[k];

    for(int i = 0; i<k;i++){
        x_array[i] = xn + dx * i;
    }

    int field_width = 15;

    cout << '+' << setfill('-') << setw(field_width) << '-' << '+' << setw(field_width) << '-' << '+' << endl;

    for (int i = 0; i < k; i++){
        cout << '|' << setfill(' ') << left << setw(field_width) << x_array[i]
        << '|' << setw(field_width)<< left << setprecision(4) << fixed << function(x_array[i]) << '+' << endl;

        cout <<'+'<< setfill('-')<<setw(field_width)<<'-'<<'+'<<setw(field_width)<<'-'<<'+'<<endl;
    }

}
