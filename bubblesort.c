#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5

void lerNumeros(int numeros[]) {
  for (int i = 0; i < TAMANHO; i++)
  {
    printf("Digite o %d numero: ", i + 1);
    scanf("%d", &numeros[i]);
  }
}

// Ordenação feita com o algoritmo de ordenação bubble sort
void ordenarNumeros(int numeros[]) {
  int aux;
  int trocou;

  for (int i = 0; i < TAMANHO; i++)
  { trocou = 0;
    for (int j = i + 1; j < TAMANHO; j++)
    {
      if (numeros[i] > numeros[j])
      {
        aux = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = aux;
        trocou = 1;
      }
    }
    if (trocou==0) break;  
  }
}

void mostrarNumeros(int numeros[]) {
  for (int i = 0; i < TAMANHO; i++)
  {
    printf("O %d numero e: %d\n", i + 1, numeros[i]);
  }
}

int main() {
  int numeros[TAMANHO];

  lerNumeros(numeros);

  ordenarNumeros(numeros);

  mostrarNumeros(numeros);

  return 0;
}