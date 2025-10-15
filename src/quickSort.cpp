#include "../include/quickSort.h"
#include <vector>
#include <algorithm>
using namespace std;

extern long long comparaciones_qs;
extern long long intercambios_qs;

void Reduce(vector<long long>& arr, long long inicio, long long final) {
    if (inicio >= final) return;           
    while (true) {                              
        long long izq = inicio;
        long long der = final;
        long long pos = izq;
        int cen = 1;
        while (cen == 1) {
            cen = 0;
            while (pos != der) {
                ++comparaciones_qs;
                if (arr[pos] <= arr[der]) {
                    --der;
                } else {
                    break;
                }
            }
            if (pos != der) {
                std::swap(arr[pos], arr[der]);
                ++intercambios_qs;
                pos = der;
                while (pos != izq) {
                    ++comparaciones_qs;
                    if (arr[pos] >= arr[izq]) {
                        ++izq;
                    } else {
                        break;
                    }
                }
                if (pos != izq) {
                    std::swap(arr[pos], arr[izq]);
                    ++intercambios_qs;
                    pos = izq;
                    cen = 1;
                }
            }
        }
        long long leftLen  = pos - inicio; 
        long long rightLen = final - pos; 
        if (leftLen > 1 && rightLen > 1) {
            if (leftLen <= rightLen) {
                Reduce(arr, inicio, pos - 1);
                inicio = pos + 1;
            } else {
                Reduce(arr, pos + 1, final);
                final = pos - 1;
            }
        } else if (leftLen > 1) {
            final = pos - 1;                    
        } else if (rightLen > 1) {
            inicio = pos + 1;              
        } else {
            break;
        }
    }
}

void quickSort(vector<long long>& arr, long long n) {
    if (n <= 1) return;
    Reduce(arr, 0, n - 1);
}