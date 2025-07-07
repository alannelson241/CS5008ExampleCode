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
    NeuHeap *heap = (NeuHeap*)malloc(sizeof(NeuHeap));
    if (!heap) {
      fprintf(stderr, "Memory allocation error\n");
      return NULL;
    }
    heap->data = (int*)malloc(sizeof(int) * capacity);
    if (!heap->data) {
      fprintf(stderr, "Memory allocation error\n");
      return NULL;
    }
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

/**
 * Frees the memory allocated for the heap.
 * @param heap A pointer to the heap to free.
 */
void free_heap(NeuHeap* heap) {
    if (heap != NULL) {
      if (heap->data != NULL) {
        free(heap->data);
        free(heap);
      }
    }
}

void __swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void __double_heap_capacity(NeuHeap *heap) {
  int new_capacity = heap->capacity * SCALE_FACTOR;
  int *new_data = (int*)realloc(heap->data, new_capacity * sizeof(int));
  // null check
  heap->data = new_data;
  heap->capacity = new_capacity;
}

/**
 * Adds a new element to the heap.
 * @param heap A pointer to the heap.
 * @param value The value to add to the heap.
 */
void enqueue(NeuHeap* heap, int value) {
    if (heap->size == heap->capacity) {
      __double_heap_capacity(heap);
    }
    heap->data[heap->size] = value;
    int index = heap->size;
    heap->size++;

    while (index > 0) {
      int parent_index = (index-1)/2;
      if (heap->data[index] > heap->data[parent_index]) {
        __swap(&heap->data[index], &heap->data[parent_index]);
        index = parent_index;
      } else {
        break;
      }
    }
}

/**
 * Removes and returns the highest-priority element from the heap.
 * @param heap A pointer to the heap.
 * @return The value of the highest-priority element.
 */
int dequeue(NeuHeap* heap) {
    // size and null check

    int root_value = heap->data[0];
    heap->size--;
    heap->data[0] = heap->data[heap->size];

    int index = 0;
    while (index < heap->size) {
      int left_child_index = 2 * index + 1;
      int right_child_index = 2 * index + 2;
      int largest_index = index;
      if (left_child_index < heap->size && heap->data[left_child_index] > heap->data[largest_index]) {
        largest_index = left_child_index;
      }
      if (right_child_index < heap->size && heap->data[right_child_index] > heap->data[largest_index]) {
        largest_index = right_child_index;
      }
      if (largest_index != index) {
        __swap(&heap->data[index], &heap->data[largest_index]);
      } else {
        break;
      }
    }
    return root_value;
}

/**
 * Prints the elements of the heap.
 * @param heap A pointer to the heap.
 */
void print_heap(NeuHeap* heap) {
    printf("Heap: [");
    for (int i = 0; i < heap->size; i++) {
      printf("%d", heap->data[i]);
      if (i < heap->size - 1) {
        printf(", ");
      }
    }
    printf("]\n");
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