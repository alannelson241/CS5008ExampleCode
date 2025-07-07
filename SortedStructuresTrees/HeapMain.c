/**
 * Test program for the heap data structure.
 **/

#include "NeuHeap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number of elements>\n", argv[0]);
    return EXIT_FAILURE;
  }
  int num_elements = atoi(argv[1]);
  NeuHeap *heap = create_heap(num_elements);
  for (int i = 0; i < num_elements; i++) {
    enqueue(heap, rand() % 100);
  }
  print_heap(heap);
  print_heap_visually(heap);
  for (int i = 0; i < num_elements; i++) {
    printf("%d ", dequeue(heap));
  }
  printf("\n");
  free_heap(heap);

  return EXIT_SUCCESS;
}