#ifndef UTILS_H
#define UTILS_H
#include <iostream>

void printArray(int arr[], int n);

int getMax(int arr[], int size);

void swap(int& a, int& b);

int partition(int arr[], int low, int high);

void merge(int arr[], int left, int mid, int right);

double getExecutionTime(void (*sortFunc)(int[], int), int arr[], int size);

void generateRandomArray(int arr[], int size, int max);

void generateSortedArray(int arr[], int size);

void generateReverseSortedArray(int arr[], int size);

#endif // UTILS_H
