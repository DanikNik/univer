#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int fact(int n){
    if(n < 0){return 0;}
    else if(n == 0){return 1;}
    else {return (n*fact(n-1));}
}

double ** init_matrix(int dimension){
    double ** matrix = new double * [dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new double [dimension];
        for (int j = 0; j < dimension; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            matrix[i][j] = pow(pow(fact(i), -1), j);
        }
    }
    return matrix;
}


int main(int argc, char const *argv[]) {
    int dimension;
    cout << "[>] Enter new matrix dimension: ";
    cin >> dimension;

    int display_width = 80; //ширина текстового поля терминала - 80 символов
    int field_width = floor(display_width/dimension);
    cout << "[+] Calculated field_width: " << field_width << endl;

    double **matrix = init_matrix(dimension);
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << setprecision(field_width / 4) << fixed << setw(field_width) << left << setfill(' ') << matrix[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    return 0;
}
