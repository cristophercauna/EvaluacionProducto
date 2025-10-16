#include "../include/heapsort.h"
#include "../include/quickSort.h"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

long long comparaciones_qs = 0;
long long intercambios_qs = 0;

long long comparaciones_hs = 0;
long long intercambios_hs = 0;

struct Row {
    string escenario;
    string algoritmo;
    long long ms;
    long long us;
    long long ns;
    long long comparaciones;
    long long intercambios;
    long long n;
    unsigned seed;
};

void write_csv_header(ofstream& csv) {
    csv << "escenario;algoritmo;ms;us;ns;comparaciones;intercambios;n;semilla\n";
}

void write_csv_row(ofstream& csv, const Row& r) {
    csv << r.escenario << ';'
        << r.algoritmo << ';'
        << r.ms << ';'
        << r.us << ';'
        << r.ns << ';'
        << r.comparaciones << ';'
        << r.intercambios << ';'
        << r.n << ';'
        << r.seed << '\n';
}

int main(){
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(0, 1000000);

    long long n;
    cin >> n;
    vector<long long> A(n);
    vector<long long> Ai(n);

    ofstream csv("metricas.csv", ios::app);
    if (csv.tellp() == 0) write_csv_header(csv);

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

     write_csv_row(csv, Row{
        "Aleatorio","QuickSort",
        chrono::duration_cast<chrono::milliseconds>(end_qs - begin_qs).count(),
        chrono::duration_cast<chrono::microseconds>(end_qs - begin_qs).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_qs - begin_qs).count(),
        comparaciones_qs, intercambios_qs, n, seed
    });

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

    write_csv_row(csv, Row{
        "Aleatorio","HeapSort",
        chrono::duration_cast<chrono::milliseconds>(end_hs - begin_hs).count(),
        chrono::duration_cast<chrono::microseconds>(end_hs - begin_hs).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_hs - begin_hs).count(),
        comparaciones_hs, intercambios_hs, n, seed
    });

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

    write_csv_row(csv, Row{
        "Ascendente","QuickSort",
        chrono::duration_cast<chrono::milliseconds>(end_qs_asc - begin_qs_asc).count(),
        chrono::duration_cast<chrono::microseconds>(end_qs_asc - begin_qs_asc).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_qs_asc - begin_qs_asc).count(),
        comparaciones_qs, intercambios_qs, n, seed
    });

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

    write_csv_row(csv, Row{
        "Ascendente","HeapSort",
        chrono::duration_cast<chrono::milliseconds>(end_hs_asc - begin_hs_asc).count(),
        chrono::duration_cast<chrono::microseconds>(end_hs_asc - begin_hs_asc).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_hs_asc - begin_hs_asc).count(),
        comparaciones_hs, intercambios_hs, n, seed
    });

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

    write_csv_row(csv, Row{
        "Descendente","QuickSort",
        chrono::duration_cast<chrono::milliseconds>(end_qs_desc - begin_qs_desc).count(),
        chrono::duration_cast<chrono::microseconds>(end_qs_desc - begin_qs_desc).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_qs_desc - begin_qs_desc).count(),
        comparaciones_qs, intercambios_qs, n, seed
    });

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

    write_csv_row(csv, Row{
        "Descendente","HeapSort",
        chrono::duration_cast<chrono::milliseconds>(end_hs_desc - begin_hs_desc).count(),
        chrono::duration_cast<chrono::microseconds>(end_hs_desc - begin_hs_desc).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_hs_desc - begin_hs_desc).count(),
        comparaciones_hs, intercambios_hs, n, seed
    });

    for (long long i = 0; i < n; i++) A[i] = i;
    Ai = A;

    int swaps = n * 0.05; // 5% del tamaño
    for (int i = 0; i < swaps; i++) {
        int x = rng() % n;
        int y = rng() % n;
        swap(A[x], A[y]);
    }
    Ai = A;

    cout << "///CASI ORDENADO (5%)///\n";
    chrono::steady_clock::time_point begin_qs_near = chrono::steady_clock::now();
    quickSort(A, n);
    chrono::steady_clock::time_point end_qs_near = chrono::steady_clock::now();

    cout << "///QUICKSORT///\n";
    cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds>(end_qs_near - begin_qs_near).count() << "[ms]\n";
    cout << "Comparaciones (QuickSort): " << comparaciones_qs << '\n';
    cout << "Intercambios (QuickSort): "  << intercambios_qs  << '\n';

    write_csv_row(csv, Row{
        "Casi ordenado","QuickSort",
        chrono::duration_cast<chrono::milliseconds>(end_qs_near - begin_qs_near).count(),
        chrono::duration_cast<chrono::microseconds>(end_qs_near - begin_qs_near).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_qs_near - begin_qs_near).count(),
        comparaciones_qs, intercambios_qs, n, seed
    });

    comparaciones_qs = intercambios_qs = 0;
    comparaciones_hs = intercambios_hs = 0;

    chrono::steady_clock::time_point begin_hs_near = chrono::steady_clock::now();
    heapSort(Ai, n);
    chrono::steady_clock::time_point end_hs_near = chrono::steady_clock::now();

    cout << "///HEAPSORT///\n";
    cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds>(end_hs_near - begin_hs_near).count() << "[ms]\n";
    cout << "Comparaciones (HeapSort): " << comparaciones_hs << '\n';
    cout << "Intercambios (HeapSort): "  << intercambios_hs  << '\n';

    write_csv_row(csv, Row{
        "Casi ordenado","HeapSort",
        chrono::duration_cast<chrono::milliseconds>(end_hs_near - begin_hs_near).count(),
        chrono::duration_cast<chrono::microseconds>(end_hs_near - begin_hs_near).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_hs_near - begin_hs_near).count(),
        comparaciones_hs, intercambios_hs, n, seed
    });


    int valores_unicos = 10 + (rng() % 11); // entre 10 y 20
    vector<long long> base(valores_unicos);
    for (int i = 0; i < valores_unicos; i++) base[i] = dist(rng) % 1000000;

    for (long long i = 0; i < n; i++) {
        A[i] = base[rng() % valores_unicos];
    }
    Ai = A;

    cout << "///CON DUPLICADOS///\n";
    chrono::steady_clock::time_point begin_qs_dup = chrono::steady_clock::now();
    quickSort(A, n);
    chrono::steady_clock::time_point end_qs_dup = chrono::steady_clock::now();
    
    cout << "///QUICKSORT///\n";
    cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds>(end_qs_dup - begin_qs_dup).count() << "[ms]\n";
    cout << "Comparaciones (QuickSort): " << comparaciones_qs << '\n';
    cout << "Intercambios (QuickSort): "  << intercambios_qs  << '\n';

    write_csv_row(csv, Row{
        "Duplicados","QuickSort",
        chrono::duration_cast<chrono::milliseconds>(end_qs_dup - begin_qs_dup).count(),
        chrono::duration_cast<chrono::microseconds>(end_qs_dup - begin_qs_dup).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_qs_dup - begin_qs_dup).count(),
        comparaciones_qs, intercambios_qs, n, seed
    });

    comparaciones_qs = intercambios_qs = 0;
    comparaciones_hs = intercambios_hs = 0;

    chrono::steady_clock::time_point begin_hs_dup = chrono::steady_clock::now();
    heapSort(Ai, n);
    chrono::steady_clock::time_point end_hs_dup = chrono::steady_clock::now();

    cout << "///HEAPSORT///\n";
    cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds>(end_hs_dup - begin_hs_dup).count() << "[ms]\n";
    cout << "Comparaciones (HeapSort): " << comparaciones_hs << '\n';
    cout << "Intercambios (HeapSort): "  << intercambios_hs  << '\n';

    write_csv_row(csv, Row{
        "Duplicados","HeapSort",
        chrono::duration_cast<chrono::milliseconds>(end_hs_dup - begin_hs_dup).count(),
        chrono::duration_cast<chrono::microseconds>(end_hs_dup - begin_hs_dup).count(),
        chrono::duration_cast<chrono::nanoseconds>(end_hs_dup - begin_hs_dup).count(),
        comparaciones_hs, intercambios_hs, n, seed
    });

    cout << endl << "SEMILLA UTILIZADA: ";
    cout << seed << endl;
    return 0;
}