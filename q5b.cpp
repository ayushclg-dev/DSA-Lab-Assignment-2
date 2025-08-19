#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix (n x n): ";
    cin >> n;

    int size = 3*n - 2;   // number of non-zero elements
    int tri[100];         // 1D array to store tri-diagonal

    cout << "Enter elements of tri-diagonal matrix:\n";

    // Input values
    for (int i = 0; i < size; i++) {
        cin >> tri[i];
    }

    cout << "\nTri-Diagonal Matrix:\n";
    // Print full matrix using mapping
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << tri[n-1 + i] << " "; // main diagonal
            }
            else if (i == j+1) {
                cout << tri[i-1] << " "; // lower diagonal
            }
            else if (j == i+1) {
                cout << tri[2*n-1 + i] << " "; // upper diagonal
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
