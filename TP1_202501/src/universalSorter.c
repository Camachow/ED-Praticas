// UniversalSorter.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../include/universalSorter.h"
#include "../include/sortingAlgorithms.h"
#include "../include/metricsTracker.h"
#include "../include/dataElement.h"

// Inicializa o struct UniversalSorter
void UniversalSorter_init(UniversalSorter *sorter,
                          DataElement *array,
                          int size,
                          double costThreshold,
                          double a,
                          double b,
                          double c,
                          int seed)
{
  sorter->originalArray = array;
  sorter->arraySize = size;
  sorter->costThreshold = costThreshold;
  sorter->paramA = a;
  sorter->paramB = b;
  sorter->paramC = c;
  sorter->disruptionCount = countDisruptions(array, 0, size);
  sorter->randomSeed = seed;
  clearMetrics(&sorter->performanceMetrics);
  UniversalSorter_clearCosts(sorter);
  UniversalSorter_clearTestedSizes(sorter);
}

int UniversalSorter_getTestedSize(UniversalSorter *sorter, int index)
{
  return sorter->testedSizes[index];
}

int UniversalSorter_findLowestCost(UniversalSorter *sorter)
{
  int lowest = 0;
  for (int i = 1; i < 10; i++)
  {
    if (sorter->quickSortCosts[i] < sorter->quickSortCosts[lowest])
    {
      lowest = i;
    }
  }
  return lowest;
}

void UniversalSorter_logPerformanceMetrics(UniversalSorter *sorter,
                                           SortingMethod method,
                                           int index)
{
  double cost = sorter->paramA * sorter->performanceMetrics.comparisons + sorter->paramB * sorter->performanceMetrics.movements + sorter->paramC * sorter->performanceMetrics.functionCalls;
  if (method == QUICK_SORT)
  {
    sorter->quickSortCosts[index] = cost;
  }
  else
  {
    sorter->insertionSortCosts[index] = cost;
  }
}

void UniversalSorter_displayPerformanceMetrics(UniversalSorter *sorter,
                                               SortingMethod method,
                                               int index)
{
  double cost = (method == QUICK_SORT)
                    ? sorter->quickSortCosts[index]
                    : sorter->insertionSortCosts[index];
  printf(" cost %.9f cmp %ld move %ld calls %ld\n",
         cost,
         sorter->performanceMetrics.comparisons,
         sorter->performanceMetrics.movements,
         sorter->performanceMetrics.functionCalls);
}

void UniversalSorter_clearCosts(UniversalSorter *sorter)
{
  for (int i = 0; i < 10; i++)
  {
    sorter->quickSortCosts[i] = INFINITY;
    sorter->insertionSortCosts[i] = INFINITY;
  }
}

DataElement *UniversalSorter_duplicateArray(UniversalSorter *sorter)
{
  DataElement *copy = malloc(sizeof(DataElement) * sorter->arraySize);
  for (int i = 0; i < sorter->arraySize; i++)
  {
    copy[i] = sorter->originalArray[i];
  }
  return copy;
}

int UniversalSorter_findOptimalPartitionThreshold(UniversalSorter *sorter)
{
  int minPS = 2;
  int maxPS = sorter->arraySize;
  int testCount, bestIndex;
  float diff;
  int step = (maxPS - minPS) / 5;
  int iteration = 0;

  do
  {
    testCount = 0;
    printf("\niter %d\n", iteration);
    UniversalSorter_clearTestedSizes(sorter);
    UniversalSorter_clearCosts(sorter);

    for (int ps = minPS; ps <= maxPS; ps += (step > 0 ? step : 1))
    {
      clearMetrics(&sorter->performanceMetrics);
      sorter->testedSizes[testCount] = ps;
      sorter->testedSizes[testCount] = ps;

      UniversalSorter_selectSortingMethod(sorter, ps, -1);
      printf("mps %d", sorter->testedSizes[testCount]);
      UniversalSorter_logPerformanceMetrics(sorter, QUICK_SORT, testCount);
      UniversalSorter_displayPerformanceMetrics(sorter, QUICK_SORT, testCount);
      testCount++;
    }

    bestIndex = UniversalSorter_findLowestCost(sorter);
    UniversalSorter_computeNewRange(sorter, testCount, bestIndex, &minPS, &maxPS, &step);
    diff = UniversalSorter_computeMetricDifference(sorter, QUICK_SORT, minPS, maxPS);
    UniversalSorter_clearCosts(sorter);

    printf("nummps %d limParticao %d mpsdiff %.6f\n",
           testCount,
           sorter->testedSizes[bestIndex],
           diff);

    iteration++;
  } while (diff > sorter->costThreshold && testCount >= 5);

  return sorter->testedSizes[bestIndex];
}

void UniversalSorter_selectSortingMethod(UniversalSorter *sorter,
                                         int minPartitionSize,
                                         int disruptionThreshold)
{
  DataElement *tmp = UniversalSorter_duplicateArray(sorter);
  clearMetrics(&sorter->performanceMetrics);

  if (sorter->disruptionCount < disruptionThreshold)
  {
    insertionSort(tmp, 0, sorter->arraySize - 1, &sorter->performanceMetrics);
  }
  else
  {
    if (sorter->arraySize > minPartitionSize)
    {
      runQuickSort(tmp, 0, sorter->arraySize - 1,
                   minPartitionSize, &sorter->performanceMetrics);
    }
    else
    {
      insertionSort(tmp, 0, sorter->arraySize - 1, &sorter->performanceMetrics);
    }
  }
  free(tmp);
}

void UniversalSorter_computeNewRange(UniversalSorter *sorter,
                                     int testCount,
                                     int bestIndex,
                                     int *minPS,
                                     int *maxPS,
                                     int *step)
{
  int newMin, newMax;
  if (bestIndex == 0)
  {
    newMin = 0;
    newMax = 2;
  }
  else if (bestIndex == testCount - 1)
  {
    newMin = testCount - 3;
    newMax = testCount - 1;
  }
  else
  {
    newMin = bestIndex - 1;
    newMax = bestIndex + 1;
  }
  *minPS = sorter->testedSizes[newMin];
  *maxPS = sorter->testedSizes[newMax];
  *step = (*maxPS - *minPS) / 5;
  if (*step == 0)
    *step = 1;
}

int UniversalSorter_findDisruptionThreshold(UniversalSorter *sorter,
                                            int minPartitionSize)
{
  int minDT = 1;
  int maxDT = sorter->arraySize / 2;
  int testCount, bestIndex;
  float diff;
  int step = (maxDT - minDT) / 5;
  int iteration = 0;

  do
  {
    testCount = 0;
    printf("\niter %d\n", iteration);
    UniversalSorter_clearTestedSizes(sorter);
    UniversalSorter_clearCosts(sorter);

    for (int dt = minDT; dt <= maxDT; dt += (step > 0 ? step : 1))
    {
      clearMetrics(&sorter->performanceMetrics);
      sorter->testedSizes[testCount] = dt;

      DataElement *arrQS = UniversalSorter_insertDisruptions(sorter, dt);
      runQuickSort(arrQS, 0, sorter->arraySize - 1,
                   minPartitionSize, &sorter->performanceMetrics);
      printf("qs lq %d", sorter->testedSizes[testCount]);
      UniversalSorter_logPerformanceMetrics(sorter, QUICK_SORT, testCount);
      UniversalSorter_displayPerformanceMetrics(sorter, QUICK_SORT, testCount);

      clearMetrics(&sorter->performanceMetrics);
      DataElement *arrIS = UniversalSorter_insertDisruptions(sorter, dt);
      insertionSort(arrIS, 0, sorter->arraySize - 1, &sorter->performanceMetrics);
      printf("in lq %d", sorter->testedSizes[testCount]);
      UniversalSorter_logPerformanceMetrics(sorter, INSERTION_SORT, testCount);
      UniversalSorter_displayPerformanceMetrics(sorter, INSERTION_SORT, testCount);

      free(arrQS);
      free(arrIS);
      testCount++;
    }

    bestIndex = UniversalSorter_findSmallestDifference(sorter);
    UniversalSorter_computeNewRange(sorter, testCount, bestIndex,
                                    &minDT, &maxDT, &step);
    diff = UniversalSorter_computeMetricDifference(sorter,
                                                   INSERTION_SORT,
                                                   minDT, maxDT);
    UniversalSorter_clearCosts(sorter);

    printf("numlq %d limQuebras %d lqdiff %.6f\n",
           testCount,
           sorter->testedSizes[bestIndex],
           diff);
    iteration++;
  } while (diff > sorter->costThreshold && testCount >= 5);

  return sorter->testedSizes[bestIndex];
}

DataElement *UniversalSorter_insertDisruptions(UniversalSorter *sorter,
                                               int disruptions)
{
  DataElement *arr = UniversalSorter_duplicateArray(sorter);
  runQuickSort(arr, 0, sorter->arraySize - 1, -1, &sorter->performanceMetrics);
  srand48(sorter->randomSeed);
  shuffleArray(arr, sorter->arraySize, disruptions);
  clearMetrics(&sorter->performanceMetrics);
  return arr;
}

int UniversalSorter_findSmallestDifference(UniversalSorter *sorter)
{
  int idx = 0;
  for (int i = 1; i < 10; i++)
  {
    double diff_i = fabs(sorter->quickSortCosts[i] - sorter->insertionSortCosts[i]);
    double diff_best = fabs(sorter->quickSortCosts[idx] - sorter->insertionSortCosts[idx]);
    if (diff_i < diff_best)
      idx = i;
  }
  return idx;
}

int UniversalSorter_getSizeIndex(UniversalSorter *sorter, int value)
{
  for (int i = 0; i < 10; i++)
  {
    if (sorter->testedSizes[i] == value)
      return i;
  }
  return -1;
}

float UniversalSorter_computeMetricDifference(UniversalSorter *sorter,
                                              SortingMethod method,
                                              int minVal,
                                              int maxVal)
{
  int iMin = UniversalSorter_getSizeIndex(sorter, minVal);
  int iMax = UniversalSorter_getSizeIndex(sorter, maxVal);
  double diff = (method == QUICK_SORT)
                    ? fabs(sorter->quickSortCosts[iMax] - sorter->quickSortCosts[iMin])
                    : fabs(sorter->insertionSortCosts[iMax] - sorter->insertionSortCosts[iMin]);
  return (float)diff;
}

void UniversalSorter_clearTestedSizes(UniversalSorter *sorter)
{
  for (int i = 0; i < 10; i++)
    sorter->testedSizes[i] = -1;
}

void UniversalSorter_printDetailedAnalysis(UniversalSorter *sorter)
{
  double cost = sorter->paramA * sorter->performanceMetrics.comparisons + sorter->paramB * sorter->performanceMetrics.movements + sorter->paramC * sorter->performanceMetrics.functionCalls;
  printf("\ncost %.9f cmp %ld move %ld calls %ld\n",
         cost,
         sorter->performanceMetrics.comparisons,
         sorter->performanceMetrics.movements,
         sorter->performanceMetrics.functionCalls);
}
