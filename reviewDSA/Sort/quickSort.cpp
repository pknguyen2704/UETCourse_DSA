#include <iostream>
using namespace std;

int partition(int arr[], const int begin, const int last) {
    int pivot = arr[begin];

    int count = 0;
    for(int i = begin + 1; i <= last; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = begin + count;
    swap(arr[pivotIndex], arr[begin]);

    int i = begin, j = last;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int begin, int last) {
    if(begin >= last) {
        return;
    }
    int p = partition(arr, begin, last);
    quickSort(arr, begin, p-1);
    quickSort(arr, p+1, last);
}
int main() {

}