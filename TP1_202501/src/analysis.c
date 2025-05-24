// experiment_analysis.c
#include <stdlib.h> // para srand48, drand48
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "../include/dataElement.h"
#include "../include/metricsTracker.h"
#include "../include/sortingAlgorithms.h"
#include "../include/universalSorter.h"
#define _XOPEN_SOURCE 700

// Vetor global controlado
DataElement controlledArray[VECTOR_SIZE];

// Gera dados para regressão, ordenando o vetor e exibindo estatísticas
void GenerateRegressionData(void)
{
  MetricsTracker stats;
  clearMetrics(&stats);

  struct timeval start, end;
  gettimeofday(&start, NULL);

  // Executa QuickSort completo para coleta de métricas
  runQuickSort(controlledArray, 0, VECTOR_SIZE - 1, -1, &stats);

  gettimeofday(&end, NULL);
  double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

  printf("calls = %ld\n", stats.functionCalls);
  printf("compares = %ld\n", stats.comparisons);
  printf("moves = %ld\n", stats.movements);
  printf("Tempo de execução: %.6f segundos\n", duration);
}

// Inverte a ordem dos elementos no vetor
void ReverseArray(DataElement *array, int size)
{
  for (int i = 0; i < size / 2; i++)
  {
    DataElement temp = array[i];
    array[i] = array[size - 1 - i];
    array[size - 1 - i] = temp;
  }
}

// Gera um vetor controlado com chaves aleatórias e payloads cíclicos
void GenerateControlledArray(void)
{
  long long min = (long long)pow(10, KEY_SIZE - 1);
  long long max = (long long)pow(10, KEY_SIZE) - 1;

  srand48(1); // semente fixa para reprodutibilidade

  for (int i = 0; i < VECTOR_SIZE; i++)
  {
    controlledArray[i].key = min + (long long)(drand48() * (max - min + 1));

    for (int j = 0; j < PAYLOAD_SIZE - 1; j++)
    {
      controlledArray[i].payload[j] = '0' + (j % 10);
    }
    controlledArray[i].payload[PAYLOAD_SIZE - 1] = '\0';
  }
}

// Testa um algoritmo de ordenação e exibe o relatório de desempenho
void TestAlgorithm(UniversalSorter *sorter, int partitionThreshold, int disruptionThreshold)
{
  struct timeval start, end;
  gettimeofday(&start, NULL);

  UniversalSorter_selectSortingMethod(sorter, partitionThreshold, disruptionThreshold);

  gettimeofday(&end, NULL);
  double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

  UniversalSorter_printDetailedAnalysis(sorter);
  printf("Tempo de execução: %.4f microsegundos\n", duration * 1e6);
}

// Executa a análise experimental dos algoritmos
void RunExperimentAnalysis(void)
{
  GenerateControlledArray();

  double a = 0.02043866508;
  double b = -0.007342909831;
  double c = 0.01509796695;
  double costThreshold = 30.0;
  int seed = 1;

  // Calibração dos parâmetros
  UniversalSorter calibration;
  UniversalSorter_init(&calibration, controlledArray, VECTOR_SIZE, costThreshold, a, b, c, seed);
  int partitionThreshold = UniversalSorter_findOptimalPartitionThreshold(&calibration);
  int disruptionThreshold = UniversalSorter_findDisruptionThreshold(&calibration, partitionThreshold);

  // Preparação dos testes
  UniversalSorter universalTest;
  UniversalSorter_init(&universalTest, controlledArray, VECTOR_SIZE, costThreshold, a, b, c, seed);

  UniversalSorter quickSortTest;
  UniversalSorter_init(&quickSortTest, controlledArray, VECTOR_SIZE, costThreshold, a, b, c, seed);

  UniversalSorter insertionTest;
  UniversalSorter_init(&insertionTest, controlledArray, VECTOR_SIZE, costThreshold, a, b, c, seed);

  // Execução dos testes
  printf("\nOrdenador Universal\n");
  TestAlgorithm(&universalTest, partitionThreshold, disruptionThreshold);

  printf("\nQuickSort\n");
  TestAlgorithm(&quickSortTest, -1, -1);

  printf("\nInsercao\n");
  TestAlgorithm(&insertionTest, -1, VECTOR_SIZE);
}
