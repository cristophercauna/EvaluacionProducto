#include <chrono>
#include <iostream>
#include <random>
using namespace std;

void quickSort (long long A[], long long n);

int main(){
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(0, 1000);

    long long n;
    cin >> n;
    long long A[n];

    for (long i = 0; i < n; i++){
        A[i] = dist(rng);
    }

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    quickSort(A, n);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << endl;

    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[us]" << endl;

    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "[ns]" << endl;

    return 0;
}

void Reduce(long long A[], long long inicio, long long final){
    int izq, der, pos, cen;
    izq = inicio;
    der = final;
    pos = izq;
    cen = 1; 

    while (cen == 1){
        cen = 0;
        while (A[pos] <= A[der] && pos != der){
            der = der - 1;
        }

        if (pos != der){
           int aux = A[pos];
           A[pos] = A[der];
           A[der] = aux;
           pos = der;
           
           while (A[pos] >= A[izq] && pos != izq){
            izq = izq + 1;
           }

           if (pos != izq){
                aux = A[pos];
                A[pos] = A[izq];
                A[izq] = aux;
                pos = izq;
                cen = 1;
           }
        }
        if (pos - 1 > inicio){
            Reduce (A, inicio, pos - 1);
        }

        if (pos + 1 < final){
            Reduce (A, pos + 1, final);
        }
    }
}

void quickSort (long long A[], long long n){
    Reduce (A, 0, n);
}