#include <iostream>
using namespace std;

int main() {
    int A[20][3], B[20][3], C[100][3];
    int n1, n2;

    cout << "Enter first matrix (rows cols nonZero): ";
    cin >> A[0][0] >> A[0][1] >> A[0][2];
    for (int i = 1; i <= A[0][2]; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter second matrix (rows cols nonZero): ";
    cin >> B[0][0] >> B[0][1] >> B[0][2];
    for (int i = 1; i <= B[0][2]; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible!" << endl;
        return 0;
    }

    int k = 1;
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {
            if (A[i][1] == B[j][0]) {
                int row = A[i][0];
                int col = B[j][1];
                int val = A[i][2] * B[j][2];

                int found = 0;
                for (int m = 1; m < k; m++) {
                    if (C[m][0] == row && C[m][1] == col) {
                        C[m][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    C[k][0] = row;
                    C[k][1] = col;
                    C[k][2] = val;
                    k++;
                }
            }
        }
    }

    C[0][2] = k - 1;

    cout << "\nResultant Sparse Matrix in triplet form:\n";
    for (int i = 0; i <= C[0][2]; i++) {
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
    }
    return 0;
}
