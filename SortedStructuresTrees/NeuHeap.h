#ifndef NEU_HEAP_H
#define NEU_HEAP_H


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SCALE_FACTOR 2

typedef struct NeuHeap {
  int *data;
  int size;
  int capacity;
} NeuHeap;

NeuHeap *create_heap(int capacity);
void free_heap(NeuHeap *heap);
void enqueue(NeuHeap *heap, int value);
int dequeue(NeuHeap *heap);
void print_heap(NeuHeap *heap);
void print_heap_visually(NeuHeap* heap);

#endif /* NEU_HEAP_H */