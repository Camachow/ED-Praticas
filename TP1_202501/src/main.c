// main.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenador.h"
#include "calibrador.h"

#define MAX_TAM 100000

extern int shuffleVector(int *vet, int size, int numShuffle, int seed);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Uso: %s <arquivo_entrada>\n", argv[0]);
    return 1;
  }

  FILE *f = fopen(argv[1], "r");
  if (!f)
  {
    perror("Erro ao abrir arquivo");
    return 1;
  }

  int seed, tam;
  double limiarCusto, a, b, c;
  int vetor[MAX_TAM];

  // Leitura do arquivo com verificação
  if (fscanf(f, "%d", &seed) != 1)
    return 1;
  if (fscanf(f, "%lf", &limiarCusto) != 1)
    return 1;
  if (fscanf(f, "%lf", &a) != 1)
    return 1;
  if (fscanf(f, "%lf", &b) != 1)
    return 1;
  if (fscanf(f, "%lf", &c) != 1)
    return 1;
  if (fscanf(f, "%d", &tam) != 1)
    return 1;

  for (int i = 0; i < tam; i++)
  {
    if (fscanf(f, "%d", &vetor[i]) != 1)
      return 1;
  }
  fclose(f);

  // Determina limiares calibrados
  int minTamParticao = determina_limiar_particao(vetor, tam, limiarCusto, a, b, c);
  int limiarQuebras = determina_limiar_quebras(tam, limiarCusto, a, b, c, seed);

  // Chamada do Ordenador Universal
  ordenador_universal(vetor, tam, minTamParticao, limiarQuebras);

  // Estatísticas
  long long cmp, mov, calls;
  get_stats(&cmp, &mov, &calls);
  double custo = a * cmp + b * mov + c * calls;

  printf("cmp %lld move %lld calls %lld\n", cmp, mov, calls);
  printf("cost %.9lf\n", custo);

  return 0;
}
