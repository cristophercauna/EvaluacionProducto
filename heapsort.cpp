#include<iostream>
#include<chrono>
#include <random>
using namespace std;
void heapify(long long arr[], long long n, long long i);
void heapSort(long long arr[], long long n);
int main(){
    long long n;
    cin >> n;
    long long arr[100000];
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<long long> dist(0, 1000000);
     for (long long i = 0; i < n; i++)
        arr[i] = dist(rng);
}