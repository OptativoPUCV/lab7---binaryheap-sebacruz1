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
  if (pq->size >= pq->capac)
  {
    pq->heapArray = realloc(pq->heapArray, pq->capac * 2); 
    
  }
  pq->heapArray[pq->size - 1].data = data;
  pq->heapArray[pq->size - 1].priority = priority;
  int posicionActual = pq->size - 1;
  pq->size++;
  int padrePosicion = (posicionActual - 1) / 2;
  
  while (pq->heapArray[posicionActual].priority > 
          pq->heapArray[padrePosicion].priority)
  {
    if (pq->heapArray[padrePosicion].priority < 
        pq->heapArray[posicionActual].priority)      
    {
      void *aux = pq->heapArray[posicionActual].data;
      int prAux = pq->heapArray[posicionActual].priority; 
      pq->heapArray[posicionActual].data = pq->heapArray[padrePosicion].data;
      pq->heapArray[posicionActual].priority = 
        pq->heapArray[padrePosicion].priority;
      
      pq->heapArray[padrePosicion].data = aux;
      pq->heapArray[padrePosicion].priority = prAux;
      
      return;
    }
    posicionActual--;
    padrePosicion = (posicionActual - 1) / 2;
  }

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
