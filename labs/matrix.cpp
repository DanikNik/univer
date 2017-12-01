#include <iostream>
#include <cmath>
using namespace std;

double ** minor(double ** matrix, int rang, int row, int column){
  double ** minor = new int * [rang -1];
  for (size_t i = 0; i < rang-1; i++) {
    minor[i] = new double [rang - 1];
  }
  for (size_t i = 0; i < range; i++) {
    for (size_t j = 0; j < range; j++) {
      if(i == row) or (j == column){
        continue;
      }
      else{
        minor[i][j]
      }
    }
  }
}

double determinant(double **matrix, rang){
  double det = 0;
  if (rang > 2){
    for (size_t i = 0; i < rang; i++) {
      /* code */
    }
  }
}

double ** multiply_matrixes(double **matrix1, double **matrix2, int rang){
    double  **matrix_out =  new double * [rang];
    for (size_t i = 0; i < rang; i++) {
        matrix_out[i] = new double [rang];
    }

    for (size_t i = 0; i < rang; i++) {
        for (size_t j = 0; j < rang; j++) {
            matrix_out[i][j] = 0;
            for (size_t z = 0; z < rang; z++) {
                matrix_out[i][j] += matrix1[i][z] * matrix2[z][j];
            }
        }
    }
    return matrix_out;
}

double ** matrix_inversion(double ** in_matrix, int rang){
    double  **matrix =  new double * [rang];
    for (size_t i = 0; i < rang; i++) {
        matrix[i] = new double [rang];
    }
    for (size_t i = 0; i < rang; i++) {
        for (size_t j = 0; j < rang; j++) {
            matrix[i][j] = in_matrix[i][j] + 1;
        }
    }
    return matrix;
}

int main(int argc, char const *argv[]) {
    int matrix_rang;
    cout << "[?] Enter matrix dimension: ";
    cin >> matrix_rang;
    double **matrix1 = new double * [matrix_rang];
    double **matrix2 = new double * [matrix_rang];
    for (size_t i = 0; i < matrix_rang; i++) {
        matrix1[i] = new double [matrix_rang];
        matrix2[i] = new double [matrix_rang];
    }

    cout << "[*] Enter the Matrix1: \n";
    for (size_t i = 0; i < matrix_rang; i++) {
        for (size_t j = 0; j < matrix_rang; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "[*] Enter the Matrix2: \n";
    for (size_t i = 0; i < matrix_rang; i++) {
        for (size_t j = 0; j < matrix_rang; j++) {
            cin >> matrix2[i][j];
        }
    }

    double **new_matrix = multiply_matrixes(matrix1, matrix2, matrix_rang);


    cout << "[+] This is your matrix: \n";
    for (size_t i = 0; i < matrix_rang; i++) {
        for (size_t j = 0; j < matrix_rang; j++) {
            cout << new_matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
