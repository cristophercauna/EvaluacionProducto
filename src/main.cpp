#include "../include/heapsort.h"
#include "../include/quickSort.h"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

long long comparaciones_qs = 0;
long long intercambios_qs = 0;

long long comparaciones_hs = 0;
long long intercambios_hs = 0;

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
    cout << "Comparaciones (QuickSort): " << comparaciones_qs << endl;
    cout << "Intercambios (QuickSort): "  << intercambios_qs  << endl;


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

    cout << "Comparaciones (HeapSort): " << comparaciones_hs << endl;
    cout << "Intercambios (HeapSort): "  << intercambios_hs  << endl;
    return 0;
}