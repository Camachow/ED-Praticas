#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP
#include <iostream>
#include <vector>

void swap(int& a, int& b);

void heapify(std::vector<int>& arr, int n, int i);

void heapSort(std::vector<int>& arr);

#endif // HEAPSORT_HPP