//queue.c ** exemple pedagogique MIT license GF 2019 **
// Un TAD type de donnees abstrait en C
// Ne pas utiliser ceci (tel quel) en production.

#include<stdio.h>
#include<stdlib.h>
/*
  Queue a 5 propriétés.
  capacity : le maximum d'elements que la file peut contenir.
  size : le nombre actuelcurrent d'elements dans la file.
  front : est l'index du premier element dans la file (le prochain a ... etre vu, passe)
  rear : l'index du dernier element dans la file
  elements : les elements dans la file
*/
typedef struct Queue_s {
  int capacity;
  int size;
  int front;
  int rear;
  int *elements;
} Queue;

Queue * initQ(int maxElements);
void dequeueQ(Queue *Q);
int frontQ(Queue *Q);
void enqueueQ(Queue *Q,int element);
void deleteQ(Queue *Q);

/* initQueue une fonction avec un argument qui est le nombre
   d'élements que la file peut prendre. Elle retournera le pointer
   vers la file nouvellement créé */
Queue * initQ(int maxElements) {
  Queue *Q;
  Q = (Queue *)malloc(sizeof(Queue));
  /* Initialisation des proprietes */
  Q->elements = (int *)malloc(sizeof(int)*maxElements);
  Q->size = 0;
  Q->capacity = maxElements;
  Q->front = 0;
  Q->rear = -1;
  return Q;
}

void dequeueQ(Queue *Q) {
  /* Si size est zero la file est vide.  Et donc impossible de dequeue */
  if(Q->size==0) {
    printf("Queue est vide\n");
    return;
  }
  /* Removing an element is equivalent to incrementing index of front by one */
  else {
    Q->size--;
    Q->front++;
    /* As we fill elements in circular fashion */
    if(Q->front==Q->capacity) {
      Q->front=0;
    }
  }
  return;
}

int frontQ(Queue *Q) {
  if(Q->size==0) {
    printf("La Queue est vide..");
    return -1;
  }
  return Q->elements[Q->front];
}

void enqueueQ(Queue *Q,int element) {
  /* If the Queue is full, we cannot push an element into it as there is no space for it.*/
  if (Q->size == Q->capacity) {
    printf("Queue is Full\n");
  }
  else {
    Q->size++;
    Q->rear = Q->rear + 1;
    /* As we fill the queue in circular fashion */
    if (Q->rear == Q->capacity) {
       Q->rear = 0;
    }
    /* Insert the element in its rear side */
    Q->elements[Q->rear] = element;
  }
  return;
}

void deleteQ(Queue *Q) {
  free(Q->elements);
  return;
}

int main(int argc, char *argv[]) {
  Queue *Q = initQ(5);
  printf("Le premier element (front) est : %d\n",frontQ(Q));
  enqueueQ(Q,1);
  enqueueQ(Q,2);
  enqueueQ(Q,3);
  enqueueQ(Q,4);
  printf("Le premier element (front) est : %d\n",frontQ(Q));
  enqueueQ(Q,5);
  dequeueQ(Q);
  enqueueQ(Q,6);
  printf("le premier element (front) est : %d\n",frontQ(Q));
  //deleteQ(Q); //des tests
  //free(Q);  //des tests
  return 0;
}
