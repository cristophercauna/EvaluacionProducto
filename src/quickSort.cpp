#include "../include/heapsort.h"
#include<vector>
#include<algorithm>
using namespace std;

void Reduce(vector<long long>& arr, long long inicio ,long long final){
    long long izq = inicio;
    long long der = final;
    long long pos = izq;
    int cen = 1;
    while(cen == 1){
        cen = 0;
        while(arr[pos]<= arr[der] && pos != der){
            der--;
        }
        if ( pos != der){
            long long aux = arr[pos];
            arr[pos] = arr[der];
            arr[der]= aux;
            pos = der;
                while(arr[pos] >= arr[izq] && pos != izq){
                    izq++;
                }
                if(pos != izq){
                    aux = arr[pos];
                    arr[pos]=arr[izq];
                    arr[izq]= aux;
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