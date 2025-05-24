#include "../include/fileValidator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lê um inteiro estrito de token, rejeitando valores inválidos
static bool ReadStrictInteger(const char *token, int *value)
{
  char *endptr;
  long val = strtol(token, &endptr, 10);
  if (endptr == token || *endptr != '\0')
  {
    return false; // caracteres extras após inteiro
  }
  *value = (int)val;
  return true;
}

bool CheckFileFormat(const char *fileName)
{
  FILE *file = fopen(fileName, "r");
  if (!file)
  {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return false;
  }

  // Carrega todo o conteúdo em buffer
  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = malloc(fileSize + 1);
  if (!buffer)
  {
    fprintf(stderr, "Erro de alocação de memória.\n");
    fclose(file);
    return false;
  }
  size_t readLen = fread(buffer, 1, fileSize, file);
  buffer[readLen] = '\0';
  fclose(file);

  // Tokeniza o conteúdo
  char *saveptr;
  char *token = strtok_r(buffer, " \t\r\n", &saveptr);
  int initialInteger;

  // 1) Integer inicial
  if (!token || !ReadStrictInteger(token, &initialInteger))
  {
    fprintf(stderr, "Erro: esperado um inteiro inicial estrito.\n");
    free(buffer);
    return false;
  }

  // 2) Quatro doubles
  for (int i = 0; i < 4; ++i)
  {
    token = strtok_r(NULL, " \t\r\n", &saveptr);
    if (!token)
    {
      fprintf(stderr, "Erro: esperados 4 valores double após o inteiro inicial.\n");
      free(buffer);
      return false;
    }
    char *endptr;
    strtod(token, &endptr);
    if (endptr == token || *endptr != '\0')
    {
      fprintf(stderr, "Erro: valor double inválido.\n");
      free(buffer);
      return false;
    }
  }

  // 3) Tamanho do vetor (inteiro não-negativo)
  token = strtok_r(NULL, " \t\r\n", &saveptr);
  int arraySize;
  if (!token || !ReadStrictInteger(token, &arraySize) || arraySize < 0)
  {
    fprintf(stderr, "Erro: esperado inteiro válido para o tamanho do vetor.\n");
    free(buffer);
    return false;
  }

  // 4) Conteúdo do vetor: arraySize inteiros
  for (int i = 0; i < arraySize; ++i)
  {
    token = strtok_r(NULL, " \t\r\n", &saveptr);
    if (!token || !ReadStrictInteger(token, &initialInteger))
    {
      fprintf(stderr, "Erro: esperava %d inteiros, mas encontrou menos.\n", arraySize);
      free(buffer);
      return false;
    }
  }

  // 5) Verifica dados extras
  token = strtok_r(NULL, " \t\r\n", &saveptr);
  if (token)
  {
    fprintf(stderr, "Erro: arquivo contém dados extras além dos esperados.\n");
    free(buffer);
    return false;
  }

  free(buffer);
  return true;
}
