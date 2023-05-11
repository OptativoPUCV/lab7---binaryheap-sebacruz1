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



void heap_push(Heap* pq, void* data, int priority)
{
  heapElem aux;
  if (pq->size >= pq->capac)
  {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = realloc(pq->heapArray, sizeof(heapElem) * pq->capac); 
    
  }
  
  if (pq->size == 0)
  {
    pq->heapArray[0].data = data;
    pq->heapArray[0].priority = priority;
    pq->size++;
    return; 
  }
  
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  int posicion = pq->size;
  int padre = (posicion - 1) / 2;

  while (pq->heapArray[posicion].priority > pq->heapArray[padre].priority)
  {
    if (pq->heapArray[posicion].priority > pq->heapArray[padre].priority)
    {
      aux = pq->heapArray[posicion];
      pq->heapArray[posicion] = pq->heapArray[padre];
      pq->heapArray[padre] = aux;
      posicion = padre;
      padre = (posicion - 1) / 2;
    }
  }
  
  pq->size++;

}
void heap_pop(Heap* pq)
{
  for (int i = 0; i < pq->size; i++)
  {
    pq->heapArray[i] = pq->heapArray[i + 1];
  }
  pq->size--;
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
