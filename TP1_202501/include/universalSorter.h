#ifndef UNIVERSALSORTER_H
#define UNIVERSALSORTER_H

#include "dataElement.h"
#include "metricsTracker.h"

// Métodos de ordenação suportados
typedef enum
{
  QUICK_SORT,
  INSERTION_SORT
} SortingMethod;

// Estrutura para análise universal de sorter
typedef struct
{
  DataElement *originalArray;
  int arraySize;
  int testedSizes[10];
  double quickSortCosts[10];
  double insertionSortCosts[10];
  double costThreshold;
  double paramA;
  double paramB;
  double paramC;
  int disruptionCount;
  int randomSeed;
  MetricsTracker performanceMetrics;
} UniversalSorter;

// Inicializa o sorter
void UniversalSorter_init(UniversalSorter *sorter,
                          DataElement *array,
                          int size,
                          double costThreshold,
                          double a,
                          double b,
                          double c,
                          int seed);

// Encontra limiar ótimo de partição
int UniversalSorter_findOptimalPartitionThreshold(UniversalSorter *sorter);

// Encontra limiar de disruptura
int UniversalSorter_findDisruptionThreshold(UniversalSorter *sorter, int minPartitionSize);

// Seleciona método de ordenação baseado nos limiares
void UniversalSorter_selectSortingMethod(UniversalSorter *sorter,
                                         int minPartitionSize,
                                         int disruptionThreshold);

// Exibe análise detalhada das métricas
void UniversalSorter_printDetailedAnalysis(UniversalSorter *sorter);

// Outras funções utilitárias do sorter
void UniversalSorter_clearCosts(UniversalSorter *sorter);
void UniversalSorter_clearTestedSizes(UniversalSorter *sorter);

// Insere disruptura e retorna novo array
DataElement *UniversalSorter_insertDisruptions(UniversalSorter *sorter, int disruptions);

// Computa diferença de métricas entre dois valores
float UniversalSorter_computeMetricDifference(UniversalSorter *sorter,
                                              SortingMethod method,
                                              int minVal,
                                              int maxVal);

void UniversalSorter_computeNewRange(UniversalSorter *, int, int, int *, int *, int *);
int UniversalSorter_findSmallestDifference(UniversalSorter *);

#endif // UNIVERSALSORTER_H