#include <iostream>
using namespace std;

int MissingNumber(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n; 
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    int result = MissingNumber(arr, n) ;

    cout << "Missing number is " << result<< endl;
    return 0;
}
