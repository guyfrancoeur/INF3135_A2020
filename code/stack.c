  
//stack.c ** exemple pedagogique MIT license GF 2020 **
// Un TAD type de donnees abstrait en C
// Ne pas utiliser ceci (tel quel) en production.

#include <stdio.h>
#include <stdlib.h>

// O(1) insertion
// O(1) recherche
// O(1) effacement
// O(n) espace

typedef struct elem_s {
  int element;
  struct elem_s *prev; //GF nouveau pourquoi ?
  struct elem_s *next;
} elem_t;

typedef struct pile_s {
  int size;
  elem_t *bottom; //GF nouveau pourquoi ?
  elem_t *top;
} pile_t;

//GF --->
void clean2(pile_t *_s){
  elem_t *e = _s->bottom;
  int i=0;
  while (e) {
    elem_t *t = e;
    e = e->next;
    free(t);
    ++i;
  }
  _s->size = 0;
  _s->bottom = NULL;
  _s->top = NULL;
}

//GF <---
void clean3(pile_t *_s){
  elem_t *e = _s->top;
  while (e){
   elem_t *t = e;
   e = t->prev;
   free(t);
  }
  _s->size = 0;
  _s->bottom = NULL;
  _s->top = NULL;
}

void push2(int _v, pile_t *_s){
  elem_t *e = malloc(sizeof(elem_t));
  if (_s->size == 0) { _s->bottom = e; } else { _s->top->next = e; }
  e->element = _v;
  e->prev = _s->top;
  e->next = NULL;
  _s->top = e;
  _s->size++;
}

int pop2(pile_t *_s) {
  int v = 0;
  elem_t *e = _s->top;
  if (e == NULL) return -1;
  v = e->element;
  _s->top = e->prev;
  _s->size--;
  free(e);
  return v;
}

int main(int argc, char **argv) {
  pile_t p = { 0, NULL, NULL };
  push2(10, &p);
  push2(20, &p);
  push2(30, &p);
  int val = pop2(&p);
  printf("%d, %d\n", val, p.size);
  push2(40, &p);
  push2(50, &p);
  push2(60, &p);
  val = pop2(&p);
  printf("%d, %d\n", val, p.size);
  clean3(&p);
  for (int i=0;i<100000;++i) push2(i,&p);
  printf("%d\n\n", p.size);
  for (int i=0;i<100000;++i) pop2(&p);
  printf("%d\n\n", p.size);
  for (int i=0;i<100000;++i) push2(i,&p);
  clean2(&p);
  printf("%d\n\n", p.size);
}
