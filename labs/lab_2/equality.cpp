#include <iostream>
#include <cmath>
using namespace std;

int solve(float a, float b, float c){
    if (a == 0){
        if (b == 0){
            if (c == 0){
                cout << "[inf] infinity\n";
                return 1;
            }
            else{
                cout << "[0] no solutions\n";
                return 1;
            }
        }
        else{
            cout << "[1] solution is " << -c/b << '\n';
            return 1;
        }
    }
    else{
        float descriminant = b*b - 4*a*c;
        if (descriminant >= 0){
            if (descriminant == 0){
                float x0 = -b/(2*a);
                cout << "[1] solution is " << x0 << endl;
            }
            else{
                float decr_sqrt = sqrt(descriminant)/(2*a);
                float x1 = -b/(2*a) + decr_sqrt;
                float x2 = -b/(2*a) - decr_sqrt;
                cout << "[2] solutions are " << x1 << " and " << x2 << endl;
                return 1;
            }
        }
        else{
            cout << "[0] no solutions\n";
            return 1;
        }
    }
}

int main(){
    float a, b, c;
    cout << "[?] enter 3 real indexes splitting with 'SPACE' symbol: \n[?]values: ";
    cin >> a >> b >> c;
    solve(a, b, c);
    return 0;
}
