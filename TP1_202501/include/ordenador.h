// ordenador.h
#ifndef ORDENADOR_H
#define ORDENADOR_H

// Interface pública
void reset_stats();
void get_stats(long long *cmp, long long *mov, long long *calls);
int conta_quebras(int *v, int n);
void insertion_sort(int *v, int n);
void quick_sort(int *v, int n, int minPart);
void ordenador_universal(int *v, int n, int minPart, int limiarQ);

#endif // ORDENADOR_H
