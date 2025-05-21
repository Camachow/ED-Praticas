// shuffle.c
#include <stdlib.h>
#include <time.h>

// Garante embaralhamento com número controlado de quebras
int shuffleVector(int *vet, int size, int numShuffle, int seed)
{
  srand48(seed);
  int p1 = 0, p2 = 0, temp;
  for (int t = 0; t < numShuffle; t++)
  {
    // Gera dois índices distintos
    while (p1 == p2)
    {
      p1 = (int)(drand48() * size);
      p2 = (int)(drand48() * size);
    }
    // Troca os elementos
    temp = vet[p1];
    vet[p1] = vet[p2];
    vet[p2] = temp;
    p1 = p2 = 0;
  }
  return 0;
}
