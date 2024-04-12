#include <stdio.h>
#include <stdlib.h>

#define ERR_NO 1
#define ERR 0

#define PRINT_ERR printf("n/a")

int **alloc_matrix(int n);
void free_matrix(int **matrix, int n);
int read_matrix(int **matrix, int n);
void print_matrix(int **matrix, int n);
void mul_matrixes(int **a, int **b, int **result, int n);

int main() {
  int n;
  int **a = NULL, **b = NULL, **result = NULL;
  if (scanf("%d", &n) != 1 || n <= 0) {
    PRINT_ERR;
  } else {
    a = alloc_matrix(n);
    b = alloc_matrix(n);
    result = alloc_matrix(n);
    if (!a || !b || !result) {
      PRINT_ERR;
    } else if (read_matrix(a, n) == ERR || read_matrix(b, n) == ERR) {
      PRINT_ERR;
    } else {
      mul_matrixes(a, b, result, n);
      print_matrix(result, n);
    }
  }
  free_matrix(a, n);
  free_matrix(b, n);
  free_matrix(result, n);

  return 0;
}

int **alloc_matrix(int n) {
  int check = ERR_NO;
  int **result = malloc(n * sizeof(int *));
  if (!result) {
    check = ERR;
  }
  for (int i = 0; i < n && check != ERR; ++i) {
    result[i] = malloc(n * sizeof(int));
    if (!result[i]) {
      check = ERR;
    }
  }
  if (check == ERR) {
    free(result);
    result = NULL;
  }

  return result;
}

void free_matrix(int **matrix, int n) {
  for (int i = 0; i < n; ++i) {
    free(matrix[i]);
  }
  free(matrix);
}

int read_matrix(int **matrix, int n) {
  int check = ERR_NO;
  for (int i = 0; i < n && check == ERR_NO; ++i) {
    for (int j = 0; j < n && check == ERR_NO; ++j) {
      if (scanf("%d", &matrix[i][j]) != 1)
        check = ERR;
    }
  }

  return check;
}

void print_matrix(int **matrix, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d", matrix[i][j]);
      if (j != n - 1)
        printf(" ");
    }
    if (i != n - 1)
      printf("\n");
  }
}

void mul_matrixes(int **a, int **b, int **result, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      result[i][j] = 0;
      for (int k = 0; k < n; ++k) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}
