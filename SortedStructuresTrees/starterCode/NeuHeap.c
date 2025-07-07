/**
* Starter code for Code Along Heap
*
**/

#include "NeuHeap.h"

/**
 * Creates a new heap with the given capacity.
 * @param capacity The maximum number of elements the heap can hold.
 * @return A pointer to the newly created heap.
 */
NeuHeap* create_heap(int capacity) {
    // TODO: Implement
    return NULL;
}

/**
 * Frees the memory allocated for the heap.
 * @param heap A pointer to the heap to free.
 */
void free_heap(NeuHeap* heap) {
    // TODO: Implement
}

/**
 * Adds a new element to the heap.
 * @param heap A pointer to the heap.
 * @param value The value to add to the heap.
 */
void enqueue(NeuHeap* heap, int value) {
    // TODO: Implement
}

/**
 * Removes and returns the highest-priority element from the heap.
 * @param heap A pointer to the heap.
 * @return The value of the highest-priority element.
 */
int dequeue(NeuHeap* heap) {
    // TODO: Implement
    return 0;
}

/**
 * Prints the elements of the heap.
 * @param heap A pointer to the heap.
 */
void print_heap(NeuHeap* heap) {
    // TODO: Implement
}

/**
 * Prints the heap in a visual format.
 * @param heap A pointer to the heap.
 */
 void print_heap_visually(NeuHeap *heap) {
    if (heap == NULL || heap->size == 0) {
      printf("Heap is empty\n");
      return;
    }
    // Print the heap in a visual format
  
    int max_level = 0;
    int temp_size = heap->size;
    while (temp_size > 0) {
      temp_size = temp_size / 2;
      max_level++;
    }
  
    for (int i = 0; i < max_level; i++) {
      int start_index = (1 << i) - 1;     // First index at this level
      int end_index = (1 << (i + 1)) - 1; // One past the last index at this level
  
      // Print leading spaces for centering
      int spaces = (1 << (max_level - i - 1)) - 1;
      for (int s = 0; s < spaces; s++) {
        printf("  ");
      }
  
      // Print nodes at this level
      for (int j = start_index; j < end_index && j < heap->size; j++) {
        printf("%2d", heap->data[j]);
  
        // Print spaces between nodes at this level
        if (j < end_index - 1 && j + 1 < heap->size) {
          int between_spaces = (1 << (max_level - i)) - 1;
          for (int s = 0; s < between_spaces; s++) {
            printf("  ");
          }
        }
      }
      printf("\n");
    }
    printf("\n");
  }