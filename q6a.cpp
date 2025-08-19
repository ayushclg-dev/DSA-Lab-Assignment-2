#include <iostream>
using namespace std;

void transpose(int mat[20][3], int trans[20][3]) {
    int rows = mat[0][0], cols = mat[0][1], nonZero = mat[0][2];
    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    int k = 1;
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= nonZero; i++) {
            if (mat[i][1] == c) {
                trans[k][0] = mat[i][1];
                trans[k][1] = mat[i][0];
                trans[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

int main() {
    int mat[20][3], trans[20][3];

    cout << "Enter rows, cols, non-zero count: ";
    cin >> mat[0][0] >> mat[0][1] >> mat[0][2];

    cout << "Enter triplet (row col value):\n";
    for (int i = 1; i <= mat[0][2]; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    transpose(mat, trans);

    cout << "\nTranspose in triplet form:\n";
    for (int i = 0; i <= trans[0][2]; i++) {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
    }
    return 0;
}
