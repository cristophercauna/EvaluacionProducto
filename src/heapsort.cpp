#include<iostream>
#include<chrono>
#include <random>
#include<vector>
using namespace std;
void heapify(vector<long long>& arr, long long n, long long i);
void heapSort(vector<long long>& arr, long long n);
int main(){
    long long n;
    cin >> n;
    vector<long long> arr(n);
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<long long> dist(0, 1000000);
     for (long long i = 0; i < n; i++)
        arr[i] = dist(rng);
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    heapSort(arr, n);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout<<"Time difference = ";
    cout<<chrono:: duration_cast<chrono::milliseconds>(end - begin).count()<<"[ms]"<<endl;
    cout<<"Time difference = ";
    cout<<chrono:: duration_cast<chrono::microseconds> (end - begin).count()<<"[us] "<<endl;
    cout<<"Time difference = ";
    cout<<chrono:: duration_cast<chrono:: nanoseconds> (end - begin).count()<< "[ns]" <<endl;

    return 0;
}
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