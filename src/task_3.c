#include <stdio.h>
#include <stdlib.h>

#define N 20

#define ERR 1
#define ERR_NO 0

#define PRINT_ERR printf("n/a")

typedef struct {
  char name[N + 1];
  char last_name[N + 1];
  int height;
} Person_t;

int read_positive_num(int *num);
int read_persons(Person_t *person, int n);
void output(Person_t *person, int n, int min_height);

int main() {
  int n;
  Person_t *data = NULL;
  int min_height;

  int check = read_positive_num(&n);
  if (check != ERR) {
    data = malloc(sizeof(Person_t) * n);
    if (!data) {
      check = ERR;
    } else if (read_persons(data, n) == ERR) {
      check = ERR;
    } else if (read_positive_num(&min_height) == ERR) {
      check = ERR;
    } else {
      output(data, n, min_height);
    }
  }

  free(data);

  if (check == ERR) {
    PRINT_ERR;
  }

  return 0;
}

int read_positive_num(int *num) {
  int check = ERR_NO;
  if (scanf("%d", num) != 1 || *num <= 0) {
    check = ERR;
  }

  return check;
}

int read_persons(Person_t *person, int n) {
  int check = ERR_NO;
  for (int i = 0; i < n && check != ERR; ++i) {
    if (scanf("%s", person[i].name) != 1 ||
        scanf("%s", person[i].last_name) != 1 ||
        scanf("%d", &person[i].height) != 1 || person[i].height <= 0)
      check = ERR;
  }
  return check;
}

void output(Person_t *person, int n, int min_height) {
  int counter = 0;
  for (int i = 0; i < n; ++i) {
    if (person[i].height >= min_height) {
      if (counter > 0) {
        printf(", ");
      }
      printf("%s %s", person[i].name, person[i].last_name);
      ++counter;
    }
  }
  if (counter == 0) {
    printf("Nothing");
  }
}
