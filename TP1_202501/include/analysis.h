#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "universalSorter.h"
#include "dataElement.h"
#include "metricsTracker.h"

// Gera dados de regressão e imprime estatísticas
void GenerateRegressionData(void);

// Inverte um array de DataElement de tamanho 'size'
void ReverseArray(DataElement *array, int size);

// Preenche controlledArray com chaves aleatórias e payloads cíclicos
void GenerateControlledArray(void);

// Testa um sorter e imprime métricas de desempenho
void TestAlgorithm(UniversalSorter *sorter, int partitionThreshold, int disruptionThreshold);

// Executa todo o experimento de análise
void RunExperimentAnalysis(void);

#endif // ANALYSIS_H