#include "../include/heapsort.h"
#include<vector>
#include<algorithm>
using namespace std;

extern long long comparaciones_qs;
extern long long intercambios_qs;

void Reduce(vector<long long>& arr, long long inicio ,long long final){
    long long izq = inicio;
    long long der = final;
    long long pos = izq;
    int cen = 1;
    while(cen == 1){
        cen = 0;
        while (pos != der) {
            comparaciones_qs++;
            if (arr[pos] <= arr[der]) {
                der--;
            }
            else {
                break;
            }
        }
        if ( pos != der){
            long long aux = arr[pos];
            arr[pos] = arr[der];
            arr[der]= aux;
            intercambios_qs++;
            pos = der;

                while (pos != izq) {
                comparaciones_qs++;
                if (arr[pos] >= arr[izq]) {
                    izq++;
                }
                else {
                    break;
                }
            }
            if(pos != izq){
                aux = arr[pos];
                arr[pos]=arr[izq];
                arr[izq]= aux;
                intercambios_qs++;
                pos = izq;
                cen = 1;
            } 
        }
       if(pos - 1 > inicio)
       Reduce(arr,inicio,pos-1); 
       if(pos + 1 < final)
       Reduce(arr,pos+1,final);
    }
}

void quickSort(vector<long long>& arr, long long n){
    Reduce(arr,0,n-1);
}