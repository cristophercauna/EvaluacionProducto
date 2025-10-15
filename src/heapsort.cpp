#include "../include/heapsort.h"
#include<vector>
#include<algorithm>
using namespace std;
void heapify(vector<long long>& arr, long long n, long long i) {
    long long largest = i;
    long long left = 2 * i + 1;
    long long right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(vector<long long>& arr, long long n) {
    for (long long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (long long i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}