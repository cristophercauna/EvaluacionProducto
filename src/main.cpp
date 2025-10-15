#include "../include/heapsort.h"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main(){
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(0, 1000);

    long long n;
    cin >> n;
    vector<long long> A(n);
    vector<long long> Ai(n);

    for (long i = 0; i < n; i++){
        A[i] = dist(rng);
    }
    Ai = A;

    chrono::steady_clock::time_point begin_qs = chrono::steady_clock::now();
    quickSort(A, n);
    chrono::steady_clock::time_point end_qs = chrono::steady_clock::now();

    cout << "///QUICKSORT///" << endl;
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::milliseconds>(end_qs - begin_qs).count() << "[ms]" << endl;

    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::microseconds>(end_qs - begin_qs).count() << "[us]" << endl;

    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::nanoseconds>(end_qs - begin_qs).count() << "[ns]" << endl;

    chrono::steady_clock::time_point begin_hs = chrono::steady_clock::now();
    heapSort(Ai, n);
    chrono::steady_clock::time_point end_hs = chrono::steady_clock::now();

    cout << endl << "///HEAPSORT///" << endl;
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::milliseconds>(end_hs - begin_hs).count() << "[ms]" << endl;

    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::microseconds>(end_hs - begin_hs).count() << "[us]" << endl;

    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::nanoseconds>(end_hs - begin_hs).count() << "[ns]" << endl;

    return 0;
}