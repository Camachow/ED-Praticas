#include <stdio.h>
#include <stdlib.h>
#include "../include/dataElement.h"
#include "../include/universalSorter.h"
#include "../include/sortingAlgorithms.h"
#include "../include/fileValidator.h"
#include "../include/analysis.h"

int main(int argc, char *argv[])
{
  int size, seed, disruptions;
  int partition;
  double costThreshold, paramA, paramB, paramC;
  DataElement *array;
  const char *fileName;

  if (argc != 2)
  {
    fprintf(stderr, "Erro: É necessário fornecer o nome do arquivo como argumento.\n");
    return 1;
  }

  fileName = argv[1];
  if (!CheckFileFormat(fileName))
  {
    return 0;
  }

  FILE *file = fopen(fileName, "r");
  if (!file)
  {
    fprintf(stderr, "Erro ao abrir arquivo: %s\n", fileName);
    return 1;
  }

  if (fscanf(file, "%d", &seed) != 1 ||
      fscanf(file, "%lf", &costThreshold) != 1 ||
      fscanf(file, "%lf", &paramA) != 1 ||
      fscanf(file, "%lf", &paramB) != 1 ||
      fscanf(file, "%lf", &paramC) != 1 ||
      fscanf(file, "%d", &size) != 1)
  {
    fprintf(stderr, "Erro ao ler parâmetros do arquivo\n");
    fclose(file);
    return 1;
  }

  array = (DataElement *)malloc(sizeof(DataElement) * size);
  if (!array)
  {
    fprintf(stderr, "Erro de alocação de memória\n");
    fclose(file);
    return 1;
  }

  for (int i = 0; i < size; i++)
  {
    int element;
    if (fscanf(file, "%d", &element) != 1)
    {
      fprintf(stderr, "Erro ao ler elemento #%d\n", i);
      free(array);
      fclose(file);
      return 1;
    }
    array[i].key = element;
  }
  fclose(file);

  UniversalSorter test;
  UniversalSorter_init(&test, array, size, costThreshold, paramA, paramB, paramC, seed);
  disruptions = countDisruptions(array, 0, size);
  printf("size %d seed %d breaks %d\n", size, seed, disruptions);

  partition = UniversalSorter_findOptimalPartitionThreshold(&test);
  partition = UniversalSorter_findDisruptionThreshold(&test, partition);

  // Descomente a linha abaixo para executar a análise experimental completa
  // RunExperimentAnalysis();

  free(array);
  return 0;
}
