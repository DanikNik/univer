#include <iostream>
#include <cmath>
using namespace std;

float solve(float a, float b, float c){
    if (a == 0){
        if (b == 0){
            if (c == 0){
                cout << "infinity\n";
                return 1;
            }
            else{
                cout << "no solutions\n";
                return 1;
            }
        }
        else{
            cout << -c/b << '\n';
            return 1;
        }
    }
    else{
        float descriminant = b*b - 4*a*c;
        if (descriminant >= 0){
            float x1, x2;
            x1 = (-b + sqrt(descriminant))/(2*a);
            x2 = (-b - sqrt(descriminant))/(2*a);
            if (x1 == x2){
                cout << "solution is " << x1 << endl;
                return 1;
            }
            else{
                cout << "solutions are " << x1 << " and " << x2 << endl;
                return 1;
            }
        }
        else{
            cout << "no solutions\n";
            return 1;
        }
    }
}

int main(){
    int a, b, c;
    a = b = c = 0;
    cout << "[?] enter 3 indexes splitting with 'SPACE' symbol: \n";
    cin >> a >> b >> c;
    solve(a, b, c);
}
