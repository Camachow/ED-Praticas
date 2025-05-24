#ifndef DATAELEMENT_H
#define DATAELEMENT_H

#define KEY_SIZE 9       // Número de dígitos da chave
#define PAYLOAD_SIZE 16  // Tamanho do payload, incluindo o '\0'
#define VECTOR_SIZE 1000 // Defina conforme necessidade ou passe como parâmetro

// Representa elemento de dados com chave e payload
typedef struct
{
  long long key;
  char payload[PAYLOAD_SIZE];
} DataElement;

#endif // DATAELEMENT_H