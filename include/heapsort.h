#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>

void heapify(std::vector<long long>& arr, long long n, long long i);
void heapSort(std::vector<long long>& arr, long long n);

void Reduce(std::vector<long long>& arr, long long inicio ,long long final);
void quickSort(std::vector<long long>& arr, long long n);

#endif