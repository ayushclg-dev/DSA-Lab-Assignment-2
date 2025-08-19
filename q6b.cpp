#include <iostream>
using namespace std;

void addSparse(int A[20][3], int B[20][3], int C[40][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices cannot be added!" << endl;
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    int i = 1, j = 1, k = 1;
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }
    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}

int main() {
    int A[20][3], B[20][3], C[40][3];

    cout << "Enter first matrix (rows cols nonZero): ";
    cin >> A[0][0] >> A[0][1] >> A[0][2];
    cout << "Enter triplets (row col value):\n";
    for (int i = 1; i <= A[0][2]; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter second matrix (rows cols nonZero): ";
    cin >> B[0][0] >> B[0][1] >> B[0][2];
    cout << "Enter triplets (row col value):\n";
    for (int i = 1; i <= B[0][2]; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    addSparse(A, B, C);

    cout << "\nResultant Sparse Matrix in triplet form:\n";
    for (int i = 0; i <= C[0][2]; i++) {
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
    }
    return 0;
}
