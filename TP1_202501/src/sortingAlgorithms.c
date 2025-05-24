#include "sortingAlgorithms.h"
#include <stdlib.h>
#include <math.h>

static void recordComparison(MetricsTracker *tracker, int count)
{
  tracker->comparisons += count;
}

static void recordMovement(MetricsTracker *tracker, int count)
{
  tracker->movements += count;
}

static void recordFunctionCall(MetricsTracker *tracker, int count)
{
  tracker->functionCalls += count;
}

static DataElement findMedian(DataElement a, DataElement b, DataElement c)
{
  if ((a.key <= b.key) && (b.key <= c.key))
    return b;
  if ((a.key <= c.key) && (c.key <= b.key))
    return c;
  if ((b.key <= a.key) && (a.key <= c.key))
    return a;
  if ((b.key <= c.key) && (c.key <= a.key))
    return c;
  if ((c.key <= a.key) && (a.key <= b.key))
    return a;
  return b;
}

static void exchangeElements(DataElement *a, DataElement *b, MetricsTracker *tracker)
{
  DataElement temp = *a;
  *a = *b;
  recordMovement(tracker, 1);
  *b = temp;
  recordMovement(tracker, 1);
}

void clearMetrics(MetricsTracker *tracker)
{
  tracker->comparisons = 0;
  tracker->movements = 0;
  tracker->functionCalls = 0;
}

void insertionSort(DataElement *array, int left, int right, MetricsTracker *tracker)
{
  recordFunctionCall(tracker, 1);
  for (int i = left + 1; i <= right; i++)
  {
    DataElement temp = array[i];
    recordMovement(tracker, 1);
    int j = i - 1;
    recordComparison(tracker, 1);
    while ((j >= left) && (temp.key < array[j].key))
    {
      recordComparison(tracker, 1);
      array[j + 1] = array[j];
      recordMovement(tracker, 1);
      j--;
    }
    array[j + 1] = temp;
    recordMovement(tracker, 1);
  }
}

static void partitionArray(DataElement *array, int left, int right, int *i, int *j, MetricsTracker *tracker)
{
  int mid = left + (right - left) / 2;
  DataElement pivot = findMedian(array[left], array[mid], array[right]);
  *i = left;
  *j = right;

  do
  {
    while (array[*i].key < pivot.key)
    {
      recordComparison(tracker, 1);
      (*i)++;
    }
    recordComparison(tracker, 1);
    while (array[*j].key > pivot.key)
    {
      recordComparison(tracker, 1);
      (*j)--;
    }
    recordComparison(tracker, 1);
    if (*i <= *j)
    {
      exchangeElements(&array[*i], &array[*j], tracker);
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void runQuickSort(DataElement *array, int left, int right, int minPartitionSize, MetricsTracker *tracker)
{
  recordFunctionCall(tracker, 1);
  int i, j;
  partitionArray(array, left, right, &i, &j, tracker);
  recordFunctionCall(tracker, 1);

  if (left < j)
  {
    if ((j - left + 1) <= minPartitionSize)
    {
      insertionSort(array, left, j, tracker);
    }
    else
    {
      runQuickSort(array, left, j, minPartitionSize, tracker);
    }
  }
  if (i < right)
  {
    if ((right - i + 1) <= minPartitionSize)
    {
      insertionSort(array, i, right, tracker);
    }
    else
    {
      runQuickSort(array, i, right, minPartitionSize, tracker);
    }
  }
}

int shuffleArray(DataElement *array, int size, int numSwaps)
{
  for (int k = 0; k < numSwaps; k++)
  {
    int index1 = (int)(drand48() * size);
    int index2 = (int)(drand48() * size);
    while (index1 == index2)
    {
      index2 = (int)(drand48() * size);
    }
    DataElement temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
  }
  return 0;
}

int countDisruptions(DataElement *array, int start, int end)
{
  int disruptionCount = 0;
  for (int i = start; i < end - 1; i++)
  {
    if (array[i].key > array[i + 1].key)
    {
      disruptionCount++;
    }
  }
  return disruptionCount;
}
