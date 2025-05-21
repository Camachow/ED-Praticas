// calibrador.h
#ifndef CALIBRADOR_H
#define CALIBRADOR_H

int determina_limiar_particao(int *v, int tam, double limiarCusto, double a, double b, double c);
int determina_limiar_quebras(int tam, double limiarCusto, double a, double b, double c, int seed);

#endif // CALIBRADOR_H
