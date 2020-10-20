// vector.c ** exemple pedagogique MIT license GF 2019 **
// Un TAD type de donnees abstrait en C
// Ne pas utiliser ceci (tel quel) en production.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;      // slots used so far
  int capacity;  // total available slots
  int *data;     // array of integers we're storing
} Vector;

void initV(Vector *vector, int capacity);
void appendV(Vector *vector, int value);
int getV(Vector *vector, int index);
void setV(Vector *vector, int index, int value);
void extendV(Vector *vector);
void freeV(Vector *vector);

void initV(Vector *vector, int capacity) {
  // initialize size and capacity
  vector->size = 0;
  vector->capacity = capacity;

  // allocate memory for vector->data
  vector->data = malloc(sizeof(int) * vector->capacity);

  //init elements with zero
  //setV(vector, -1, 0);  //et verifier avec valgrind
  for (int i=vector->size;i < vector->capacity; ++i) {
    setV(vector, i, 0);
  }

}

void appendV(Vector *vector, int value) {
  extendV(vector);

  // append the value and increment vector->size
  vector->data[vector->size++] = value;
}

int getV(Vector *vector, int index) {
  if (index >= vector->size || index < 0) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1); //est-ce dangereux?
  }
  return vector->data[index];
}

void setV(Vector *vector, int index, int value) {
  if (index < vector->size && index >= 0) {
    vector->data[index] = value;
  }
}

void extendV(Vector *vector) {
  if (vector->size >= vector->capacity) {
    // double vector->capacity and resize the allocated memory accordingly
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
  }
}

void freeV(Vector *vector) {
  free(vector->data);
}

int main() {
  // declare and initialize a new vector
  Vector vector;
  initV(&vector,2);
  printf("capacite : %d et nombre de valeur : %d\n", vector.capacity, vector.size);

  // fill it up with 150 arbitrary values this should expand capacity
  for (int i = 200; i > -50; i--) {
    appendV(&vector, i);
  }

  setV(&vector, 921, 212984);

  printf("valeur a l'index 27: %d\n", getV(&vector, 27));
  setV(&vector, 27, 88);
  printf("valeur a l'index 27: %d\n", getV(&vector, 27));

  printf("capacite : %d et nombre de valeur : %d\n", vector.capacity, vector.size);

  freeV(&vector);
}
