#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 100

float computeDeterminant(float matrix[MATRIX_SIZE][MATRIX_SIZE], int size) {
  float Minor[MATRIX_SIZE][MATRIX_SIZE];
  int i, j, k, c1, c2;
  int determinant;
  int c[MATRIX_SIZE];
  int O = 1;

  determinant = 0;

  if (size == 2) {
    determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    return determinant;
  } else {
    for (i = 0; i < size; i++) {
      c1 = 0, c2 = 0;
      for (j = 0; j < size; j++) {
        for (k = 0; k < size; k++) {
          if (j != 0 && k != i) {
            Minor[c1][c2] = matrix[j][k];
            c2++;
            if (c2 > size - 2) {
              c1++;
              c2 = 0;
            }
          }
        }
      }
      determinant = determinant +
                    O * (matrix[0][i] * computeDeterminant(Minor, size - 1));
      O = -1 * O;
    }
  }

  return determinant;
}

void initializeMatrix(float matrix[MATRIX_SIZE][MATRIX_SIZE]){
  int i, j;
  for(i = 0;i < MATRIX_SIZE; i++){
    for(j = 0; j < MATRIX_SIZE; j++) {
      float randomNumber = (float)rand()/(float)(RAND_MAX/100);
      matrix[i][j] = randomNumber;
    }
  }
}

int main(void) {
  float res;

  float matrix[MATRIX_SIZE][MATRIX_SIZE];
  initializeMatrix(matrix);

  res = computeDeterminant(matrix, 8);
  return 0;
}
