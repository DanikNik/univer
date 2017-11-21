#include <iostream>
#include <cmath>
using namespace std;

float f1(float x){return x;}
float f2(float x){return atan(x);}
float f3(float x){return sin(100*x);}
float f4(float x){return pow(x, 4);}

float integral(float (*function)(float),float start_point, float end_point, int n){
    float calc_integral = 0;
    float delta = (end_point - start_point) / n;
    for (int i = 0; i <= n; i++) {
        calc_integral+=function(start_point + delta*i)*delta;
    }
    return calc_integral;
}

int main(int argc, char const *argv[]) {
    typedef float (*func_pointer)(float);
    func_pointer array[4] = {f1, f2, f3, f4};

    float start_x, end_x, precision;
    cin >> start_x >> end_x >> precision;

    float accuracy_delta = 1;
    int n = 2;
    float current_integral, next_integral;
    for (size_t i = 0; i < 4; i++) {
        accuracy_delta = 1;
        n = 2;
        while (accuracy_delta > precision){
            current_integral = integral(array[i], start_x, end_x, n);
            n+=1;
            next_integral = integral(array[i], start_x, end_x, n);
            accuracy_delta = abs(next_integral - current_integral);
        }
        cout <<"function f" << i << ": " << next_integral << " with " << n << " divisions\n";
    }

    return 0;
}
