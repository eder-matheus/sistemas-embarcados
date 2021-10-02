#include<stdio.h>
#include <stdlib.h>

#define SIZE 1000

void bubbleSort(int vector[], int size) {
  int aux, i, j;
  for (j = size - 1; j >= 1; j--) {
    for (i = 0; i < j; i++) {
      if (vector[i] > vector[i + 1]) {
        aux = vector[i];
        vector[i] = vector[i + 1];
        vector[i + 1] = aux;
      }
    }
  }
}

void inicializaArray(int *array){
  int i;
  for(i=0;i<SIZE;i++){
    array[i] = SIZE-i;
  }
}

int main(void) {
  int bufferMil[SIZE];

  inicializaArray(bufferMil);

  bubbleSort(bufferMil, SIZE);

  return 0;
}
