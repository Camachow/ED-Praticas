#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include "dataElement.h"
#include "metricsTracker.h"

// Reinicia métricas de tracker
void clearMetrics(MetricsTracker *tracker);

// Ordenação por inserção no intervalo [left, right]
void insertionSort(DataElement *array, int left, int right, MetricsTracker *tracker);

// Quicksort com partições mínimas
void runQuickSort(DataElement *array, int left, int right, int minPartitionSize, MetricsTracker *tracker);

// Embaralha array trocando numSwaps pares de elementos
int shuffleArray(DataElement *array, int size, int numSwaps);

// Conta inversões entre start e end-1
int countDisruptions(DataElement *array, int start, int end);

#endif // SORTINGALGORITHMS_H