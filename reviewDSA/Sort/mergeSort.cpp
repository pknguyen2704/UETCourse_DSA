#include <iostream>

using namespace std;

void merge(int arr[], int const begin, int const mid, int const last) {
    int const size1 = mid - begin + 1;
    int const size2 = last - mid;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    for(int i = 0; i < size1; i++) {
        arr1[i] = arr[begin + i];
    }
    for(int j = 0; j < size2; j++) {
        arr2[j] = arr[mid+1+j];
    }
    int index1 = 0, index2= 0, index = begin;
    while(index1 < size1 && index2 < size2) {
        if(arr1[index1] <= arr2[index2]) {
            arr[index] = arr1[index1];
            index1++;
        } else {
            arr[index] = arr2[index2];
            index2++;
        }
        index++;
    }
    while(index1 < size1) {
        arr[index] = arr1[index1];
        index++;
        index1++;
    }
    while(index2 < size2) {
        arr[index] = arr2[index2];
        index++;
        index2++;
    }
    delete[] arr1;
    delete[] arr2;
}
void mergeSort(int arr[], int const begin, int const last) {
    if(begin >= last) {
        return;
    }
    int mid = begin + (last  - begin)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, last);
    merge(arr, begin, mid, last);
}
void print(int const n, int arr[]) {
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
    mergeSort(arr, 0, n-1);
    print(n, arr);
    return 0;

}