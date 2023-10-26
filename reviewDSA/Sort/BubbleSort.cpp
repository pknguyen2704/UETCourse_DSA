#include <iostream>

using namespace std;

// SelectionSort
void bubbleSort(int n, int arr[]) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
// print array
void printArr(int n, int arr[]) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(n, arr);
    printArr(n, arr);

    return 0;
}