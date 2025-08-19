#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of Upper Triangular Matrix (n x n): ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int arr[100];  

    cout << "Enter " << size << " elements (row-wise):\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nUpper Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                cout << arr[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}
