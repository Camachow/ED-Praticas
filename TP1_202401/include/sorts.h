#ifndef SORTS_H
#define SORTS_H
#include "../include/utils.h"

void bubbleSort(int arr[], int n);

void insertionSort(float arr[], int n);

void selectionSort(int arr[], int n);

void mergeSort(int arr[], int left, int right);
//mergeSort(arr, 0, n - 1);

void quickSort(int arr[], int low, int high);

void shellSort(int arr[], int n);

void countingSort(int arr[], int n);

void bucketSort(float arr[], int n);

void countingSortRadix(int arr[], int n, int exp);

void radixSort(int arr[], int n);

#endif // SORTS_HPP