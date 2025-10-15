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
    uniform_int_distribution<int> dist(0, 1000000);

    long long n;
    cin >> n;
    vector<long long> A(n);
    vector<long long> Ai(n);

    for (long long i = 0; i < n; i++){
        A[i] = dist(rng);
    }
    Ai = A;
    cout<<"///ESCENARIO ALEATORIO////"<<endl;
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

    comparaciones_qs = intercambios_qs = 0;
    comparaciones_hs = intercambios_hs = 0;

    for( long long i=0;i<n;i++){
        A[i]=i;
    }
    Ai=A;

    cout<<"///ORDENADO ASCENDENTE///"<<endl;

    chrono::steady_clock::time_point begin_qs_asc = chrono::steady_clock::now();
    quickSort(A, n);
    chrono::steady_clock::time_point end_qs_asc = chrono::steady_clock::now();

    cout << "///QUICKSORT///" << endl;
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::milliseconds>(end_qs_asc - begin_qs_asc).count() << "[ms]" << endl;
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::microseconds>(end_qs_asc - begin_qs_asc).count() << "[us]" << endl;
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::nanoseconds>(end_qs_asc - begin_qs_asc).count() << "[ns]" << endl;

    cout << "Comparaciones (QuickSort): " << comparaciones_qs << endl;
    cout << "Intercambios (QuickSort): "  << intercambios_qs  << endl;

    chrono::steady_clock::time_point begin_hs_asc = chrono::steady_clock::now();
    heapSort(Ai, n);
    chrono::steady_clock::time_point end_hs_asc = chrono::steady_clock::now();

    cout << "///HEAPSORT///" << endl;
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::milliseconds>(end_hs_asc - begin_hs_asc).count() << "[ms]" << endl;
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::microseconds>(end_hs_asc - begin_hs_asc).count() << "[us]" << endl;
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::nanoseconds>(end_hs_asc - begin_hs_asc).count() << "[ns]" << endl;

    cout << "Comparaciones (HeapSort): " << comparaciones_hs << endl;
    cout << "Intercambios (HeapSort): "  << intercambios_hs  << endl;

    for(long long i=0;i<n;i++){
        A[i]=n-i-1;
    }
    Ai=A;

    cout<<"///ORDEN DESCENDENTE///"<<endl;

    comparaciones_qs = intercambios_qs = 0;
    comparaciones_hs = intercambios_hs = 0;

    chrono::steady_clock::time_point begin_qs_desc = chrono::steady_clock::now();
    quickSort(A, n);
    chrono::steady_clock::time_point end_qs_desc = chrono::steady_clock::now();

    cout<<"///QUICKSORT///" << endl;
    cout<<"Time difference = "; 
    cout<<chrono::duration_cast<chrono::milliseconds>(end_qs_desc - begin_qs_desc).count() << "[ms]" <<endl;
    cout<<"Time difference = "; 
    cout<<chrono::duration_cast<chrono::microseconds>(end_qs_desc - begin_qs_desc).count() << "[us]" <<endl;
    cout<<"Time difference = ";
    cout<<chrono::duration_cast<chrono::nanoseconds>(end_qs_desc - begin_qs_desc).count() << "[ns]" <<endl;
    cout<<"Comparaciones (QuickSort): "<< comparaciones_qs << endl;
    cout<<"Intercambios (QuickSort): " << intercambios_qs << endl;

    chrono::steady_clock::time_point begin_hs_desc = chrono::steady_clock::now();
    heapSort(Ai, n);
    chrono::steady_clock::time_point end_hs_desc = chrono::steady_clock::now();

    cout<<"///HEAPSORT///"<<endl;
    cout<<"Time difference = ";
    cout<<chrono::duration_cast<chrono::milliseconds>(end_hs_desc - begin_hs_desc).count() << "[ms]" <<endl;
    cout<<"Time difference = "; 
    cout<<chrono::duration_cast<chrono::microseconds>(end_hs_desc - begin_hs_desc).count() << "[us]" <<endl;
    cout<<"Time difference = "; 
    cout<<chrono::duration_cast<chrono::nanoseconds>(end_hs_desc - begin_hs_desc).count() << "[ns]" <<endl;

    cout<<"Comparaciones (HeapSort): "<< comparaciones_hs <<endl;
    cout<<"Intercambios (HeapSort): " << intercambios_hs <<endl;

    cout << endl << "SEMILLA UTILIZADA: ";
    cout << seed << endl;
    return 0;
}