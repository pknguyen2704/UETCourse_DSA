#include <iostream>

using namespace std;
// SelectionSort
void selectionSort(int n, int arr[]) {
    int index = 0;
    while(index < n-1) {
        int minIndex = index;
        for(int j = index + 1; j < n; j++) {
            if(arr[j] < arr[index]) {
                minIndex = j;
            }
        }
        int tmp = arr[minIndex];
        arr[minIndex] = arr[index];
        arr[index] = tmp;
        index++;
    }
}
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

    selectionSort(n, arr);
    printArr(n, arr);

    return 0;
}