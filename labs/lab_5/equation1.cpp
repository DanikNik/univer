#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    double T, coefficient;
    cin >> T;
    cin >> coefficient;
    cout << "[1] Iterations method:" << endl;
    double x = 0;
    double last_x = 0;
    int count = 0;
    do {
        last_x = x;
        x = coefficient*cos(x);
        count++;
    }while(abs(x - last_x) > T);
    cout << setprecision(15)<< "\t" << count <<" steps \t solution is " << x << endl;

    cout << "[2] Half devision method:" << endl;

    long double right_x = 10;
    long double left_x = -10;
    x = 0;
    count = 0;

    do{
        x = double(right_x + left_x)/2.;
        if ( x - coefficient*cos(x) > .0)
        {
            right_x = x;
        }else
        {
            left_x = x;
        }
        count++;
    }while((right_x - left_x) > T);
    cout << setprecision(15) << "\t" <<  count << " steps \t solution is " << x << endl;

    cout << "[3] Newtone's method:"<< endl;

    x = 0;
    last_x = 0;
    count = 0;
    do{
        last_x = x;
        x = last_x+(-(x - coefficient*cos(x))/(1 + coefficient*sin(x)));
        count++;
    }while(abs(x - last_x)>T);
    cout << setprecision(15) << "\t" << count << " steps \t solution is " << x << endl;

    return 0;
}
