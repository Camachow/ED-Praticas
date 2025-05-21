// calibrador.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenador.h"

#define MAX_MPS 100
#define MAX_TAM 100000

static double a, b, c;

// Função para custo
double calcula_custo(long long cmp, long long mov, long long calls)
{
  return a * cmp + b * mov + c * calls;
}

// Retorna o índice do menor custo
int menor_custo(double *custos, int n)
{
  int idx = 0;
  for (int i = 1; i < n; i++)
  {
    if (custos[i] < custos[idx])
      idx = i;
  }
  return idx;
}

// Mapeia índice para mps
int get_mps(int idx, int min, int passo)
{
  return min + idx * passo;
}

// Calcula nova faixa com base no menor custo
void calcula_nova_faixa(int idx, int *minMPS, int *maxMPS, int *passo)
{
  if (idx == 0)
  {
    *minMPS = get_mps(0, *minMPS, *passo);
    *maxMPS = get_mps(2, *minMPS, *passo);
  }
  else if (idx == 5)
  {
    *minMPS = get_mps(3, *minMPS, *passo);
    *maxMPS = get_mps(5, *minMPS, *passo);
  }
  else
  {
    *minMPS = get_mps(idx - 1, *minMPS, *passo);
    *maxMPS = get_mps(idx + 1, *minMPS, *passo);
  }
  *passo = (*maxMPS - *minMPS) / 5;
  if (*passo == 0)
    (*passo)++;
}

#include "shuffle.h"

int determina_limiar_quebras(int tam, double limiarCusto, double A, double B, double C, int seed)
{
  a = A;
  b = B;
  c = C;

  int iter = 0;
  int lqs[6];
  double custo_qs[6], custo_in[6];
  long long cmp, mov, calls;

  for (int i = 0; i < 6; i++)
    lqs[i] = 1 + i * (tam / 6);

  while (1)
  {
    printf("\niter %d\n", iter++);
    for (int i = 0; i < 6; i++)
    {
      int v1[MAX_TAM], v2[MAX_TAM];

      for (int j = 0; j < tam; j++)
        v1[j] = j;
      for (int j = 0; j < tam; j++)
        v2[j] = j;

      shuffleVector(v1, tam, lqs[i], seed);
      shuffleVector(v2, tam, lqs[i], seed);

      reset_stats();
      quick_sort(v1, tam, 2); // minPart fixo
      get_stats(&cmp, &mov, &calls);
      custo_qs[i] = calcula_custo(cmp, mov, calls);

      reset_stats();
      insertion_sort(v2, tam);
      get_stats(&cmp, &mov, &calls);
      custo_in[i] = calcula_custo(cmp, mov, calls);

      printf("qs lq %d cost %.9lf cmp %lld move %lld calls %lld\n", lqs[i], custo_qs[i], cmp, mov, calls);
      printf("in lq %d cost %.9lf cmp %lld move %lld calls %lld\n", lqs[i], custo_in[i], cmp, mov, calls);
    }

    double diff = fabs(custo_in[0] - custo_in[5]);
    int melhor = 0;
    for (int i = 1; i < 6; i++)
    {
      if (custo_in[i] < custo_in[melhor])
        melhor = i;
    }

    printf("numlq 6 limQuebras %d lqdiff %.6lf\n", lqs[melhor], diff);

    if (diff < limiarCusto || (lqs[5] - lqs[0] <= 5))
      break;

    int base = (melhor == 0) ? 0 : (melhor == 5) ? 3
                                                 : melhor - 1;
    int passo = (lqs[base + 2] - lqs[base]) / 5;
    if (passo == 0)
      passo = 1;
    for (int i = 0; i < 6; i++)
      lqs[i] = lqs[base] + i * passo;
  }

  int melhor = 0;
  for (int i = 1; i < 6; i++)
  {
    if (custo_in[i] < custo_in[melhor])
      melhor = i;
  }
  return lqs[melhor];
}

// Determina limiar de partição
int determina_limiar_particao(int *v, int tam, double limiarCusto, double A, double B, double C)
{
  a = A;
  b = B;
  c = C;

  int minMPS = 2;
  int maxMPS = tam;
  int passo = (maxMPS - minMPS) / 5;

  int iter = 0;
  double custos[6];
  long long cmp, mov, calls;
  int mps_atual[6];

  while (1)
  {
    printf("\niter %d\n", iter++);

    int num = 0;
    for (int t = minMPS; t <= maxMPS && num < 6; t += passo)
    {
      int vcopy[MAX_TAM];
      for (int i = 0; i < tam; i++)
        vcopy[i] = v[i];

      ordenador_universal(vcopy, tam, t, tam);
      get_stats(&cmp, &mov, &calls);

      custos[num] = calcula_custo(cmp, mov, calls);
      mps_atual[num] = t;

      printf("mps %d cost %.9lf cmp %lld move %lld calls %lld\n",
             t, custos[num], cmp, mov, calls);
      num++;
    }

    int idx = menor_custo(custos, num);
    double diff = fabs(custos[0] - custos[num - 1]);

    printf("nummps %d limParticao %d mpsdiff %.6lf\n",
           num, mps_atual[idx], diff);

    if (diff < limiarCusto || num < 6)
      break;
    calcula_nova_faixa(idx, &minMPS, &maxMPS, &passo);
  }
  return mps_atual[menor_custo(custos, 6)];
}
