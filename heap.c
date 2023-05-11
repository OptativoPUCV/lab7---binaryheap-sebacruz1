#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
  if (pq->size == 0) return NULL;
  
  void *top = pq->heapArray[0].data;
  return top;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap *new; 
  new = malloc(3 * sizeof(Heap));
  new->heapArray = malloc(3 * sizeof(Heap));
  new->size = 0; 
  new->capac = 3;

  return new;
}
