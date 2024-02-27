#include <iostream>
#include <algorithm>
using namespace std;
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int partition_index = i + 1;
        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index + 1, high);
    }
}
void bucketSort(int arr[], int n) {
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        max_val = max(max_val, arr[i]);
        min_val = min(min_val, arr[i]);
    }
    int range = (max_val - min_val) / n + 1;
    int buckets[n][n];
    int bucket_sizes[n] = {0};
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_val) / range;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        quicksort(buckets[i], 0, bucket_sizes[i] - 1);
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    bucketSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}