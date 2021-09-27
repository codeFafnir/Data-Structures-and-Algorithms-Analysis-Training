#include <bits/stdc++.h>
using namespace std;

int** initialize_matrix(int n) {
    int** mat = new int*[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[n];
    return mat;
}

void input_matrix(int** mat, int n) {
    cout << "Enter matrix: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
}

void output_matrix(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';
}


int** add_mat(int** mat1, int** mat2, int n) {
    int** res = initialize_matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = mat1[i][j] + mat2[i][j];
    return res;
}

int** sub_mat(int** mat1, int** mat2, int n) {
    int** res = initialize_matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = mat1[i][j] - mat2[i][j];
    return res;
}

int** strassen_multiply(int** A, int** B, int n) {
    if (n == 1) {
        int** Z = initialize_matrix(1);
        Z[0][0] = A[0][0] * B[0][0];
        return Z;
    }

    int k = n / 2;

    int** A11 = initialize_matrix(k);
    int** A12 = initialize_matrix(k);
    int** A21 = initialize_matrix(k);
    int** A22 = initialize_matrix(k);
    
    int** B11 = initialize_matrix(k);
    int** B12 = initialize_matrix(k);
    int** B21 = initialize_matrix(k);
    int** B22 = initialize_matrix(k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }
    }

    int** P1 = strassen_multiply(A11, sub_mat(B12, B22, k), k);
    int** P2 = strassen_multiply(add_mat(A11, A12, k), B22, k);
    int** P3 = strassen_multiply(add_mat(A21, A22, k), B11, k);
    int** P4 = strassen_multiply(A22, sub_mat(B21, B11, k), k);
    int** P5 = strassen_multiply(add_mat(A11, A22, k), add_mat(B11, B22, k), k);
    int** P6 = strassen_multiply(sub_mat(A12, A22, k), add_mat(B21, B22, k), k);
    int** P7 = strassen_multiply(sub_mat(A11, A21, k), add_mat(B11, B12, k), k);

    int** Z11 = sub_mat(add_mat(add_mat(P5, P4, k), P6, k), P2, k);
    int** Z12 = add_mat(P1, P2, k);
    int** Z21 = add_mat(P3, P4, k);
    int** Z22 = sub_mat(sub_mat(add_mat(P5, P1, k), P3, k), P7, k);

    int** Z = initialize_matrix(n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            Z[i][j] = Z11[i][j];
            Z[i][j + k] = Z12[i][j];
            Z[k + i][j] = Z21[i][j];
            Z[k + i][k + j] = Z22[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        delete[] A11[i]; delete[] A12[i]; delete[] A21[i]; delete[] A22[i];
        delete[] B11[i]; delete[] B12[i]; delete[] B21[i]; delete[] B22[i];
        delete[] Z11[i]; delete[] Z12[i]; delete[] Z21[i]; delete[] Z22[i];
        delete[] P1[i]; delete[] P2[i]; delete[] P3[i]; delete[] P4[i]; 
        delete[] P5[i]; delete[] P6[i]; delete[] P7[i];
    }

    delete[] A11; delete[] A12; delete[] A21; delete[] A22;
    delete[] B11; delete[] B12; delete[] B21; delete[] B22;
    delete[] Z11; delete[] Z12; delete[] Z21; delete[] Z22;
    delete[] P1; delete[] P2; delete[] P3; delete[] P4;
    delete[] P5; delete[] P6; delete[] P7;

    return Z;
}

int main() {
    cout << "please enter the size of the matrix: ";
    int n;
    cin >> n;

    int** X = initialize_matrix(n);
    input_matrix(X, n);
    cout << "Matrix X: " << '\n';

    int** Y = initialize_matrix(n);
    input_matrix(Y, n);
    cout << "Matrix Y: " << '\n';

    int** Z = strassen_multiply(X, Y, n);
    cout << "Result: " << '\n';
    output_matrix(Z, n);

    for (int i = 0; i < n; i++)
        delete[] X[i];
    delete[] X;

    for (int i = 0; i < n; i++)
        delete[] Y[i];
    delete[] Y;

    for (int i = 0; i < n; i++)
        delete[] Z[i];
    delete[] Z;
}

/*
8

1 2 3 4 5 6 7 8
4 5 6 7 8 1 2 3
7 8 1 2 3 4 5 6
1 2 7 8 3 4 5 6
1 5 6 7 2 3 4 8
1 6 7 2 3 4 5 8
1 2 6 7 8 3 4 5
4 5 6 7 8 1 2 3

1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1
*/
