// ordenador.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/ordenador.h"

// Contadores globais para estatísticas
long long cmp_count = 0;
long long move_count = 0;
long long call_count = 0;

// Funções auxiliares para estatísticas
void reset_stats()
{
  cmp_count = move_count = call_count = 0;
}

void get_stats(long long *cmp, long long *mov, long long *calls)
{
  *cmp = cmp_count;
  *mov = move_count;
  *calls = call_count;
}

// Função para contar quebras no vetor
int conta_quebras(int *v, int n)
{
  int q = 0;
  for (int i = 1; i < n; i++)
  {
    cmp_count++;
    if (v[i] < v[i - 1])
      q++;
  }
  return q;
}

// Insertion Sort instrumentado
void insertion_sort(int *v, int n)
{
  call_count++;
  for (int i = 1; i < n; i++)
  {
    int chave = v[i];
    move_count++;
    int j = i - 1;
    while (j >= 0 && v[j] > chave)
    {
      cmp_count++;
      v[j + 1] = v[j];
      move_count++;
      j--;
    }
    if (j >= 0)
      cmp_count++;
    v[j + 1] = chave;
    move_count++;
  }
}

// Troca com contagem
void troca(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
  move_count += 3;
}

// Mediana de 3
int mediana3(int *v, int e, int d)
{
  int m = (e + d) / 2;
  cmp_count += 3;
  if (v[m] < v[e])
    troca(&v[m], &v[e]);
  if (v[d] < v[e])
    troca(&v[d], &v[e]);
  if (v[d] < v[m])
    troca(&v[d], &v[m]);
  troca(&v[m], &v[d - 1]); // Pivô vai pra penúltima posição
  return v[d - 1];
}

// Quicksort com mediana de 3 e fallback para insertion
void quicksort(int *v, int e, int d, int minPart)
{
  call_count++;
  if (d - e + 1 <= minPart)
  {
    insertion_sort(v + e, d - e + 1);
    return;
  }

  int pivo = mediana3(v, e, d);
  int i = e, j = d - 1;

  while (1)
  {
    while (v[++i] < pivo)
      cmp_count++;
    cmp_count++;
    while (v[--j] > pivo)
      cmp_count++;
    cmp_count++;
    if (i < j)
      troca(&v[i], &v[j]);
    else
      break;
  }

  troca(&v[i], &v[d - 1]);
  quicksort(v, e, i - 1, minPart);
  quicksort(v, i + 1, d, minPart);
}

// Interface do quicksort externa
void quick_sort(int *v, int n, int minPart)
{
  quicksort(v, 0, n - 1, minPart);
}

// Ordenador Universal
void ordenador_universal(int *v, int n, int minPart, int limiarQ)
{
  reset_stats();
  if (conta_quebras(v, n) < limiarQ)
  {
    insertion_sort(v, n);
  }
  else
  {
    if (n > minPart)
      quick_sort(v, n, minPart);
    else
      insertion_sort(v, n);
  }
}
