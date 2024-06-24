#ifndef UTILS_H
#define UTILS_H
#include <iostream>

void printIntArray(int arr[], int n);

void printFloatArray(float arr[], int n);

int getMax(int arr[], int size);

int findMax(int arr[], int size);

void swap(int& a, int& b);

int partition(int arr[], int low, int high);

void merge(int arr[], int left, int mid, int right);

#endif // UTILS_H
