<<<<<<< HEAD
/**
 * Starter code for Code Along - NeuQueue (circular queue)
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "NeuQueue.h"

/**
 * Creates a new queue with the specified initial capacity.
 *
 * @param initial_capacity The initial capacity of the queue.
 * @return A pointer to the newly created queue, or NULL if memory allocation
 * fails.
 */
NeuQueue *create_queue(size_t initial_capacity) {
  NeuQueue * queue = (NeuQueue*)malloc(sizeof(NeuQueue));
  if (queue == NULL) {
    return NULL;
  }
  queue->data = (int*)malloc(sizeof(int) * initial_capacity);
  if (queue->data == NULL) {
    free(queue);
    return NULL;
  } 
  queue->front = 0;
  queue->end = 0;
  queue->size = 0;
  queue->capacity = initial_capacity;

  return queue;
}

/**
 * Frees the memory allocated for the queue.
 *
 * @param queue A pointer to the queue to be freed.
 */
void free_queue(NeuQueue *queue) {
  if (queue != NULL) {
    free(queue->data);
    free(queue);
  }
}

/**
 * Removes and returns the front element of the queue.
 *
 * @param queue A pointer to the queue.
 * @return The value of the removed element, or -1 if the queue is empty.
 */
int dequeue(NeuQueue *queue) {
  if(is_queue_empty(queue)) {
    errno = ENODATA;
    return -1;
  }
  errno = 0;
  int value = queue->data[queue->front];
  queue->front = (queue->front + 1) % queue->capacity; // fixes a range; wraps around
  queue->size--;

  return value;
}

/**
 * Adds an element to the end of the queue.
 *
 * @param queue A pointer to the queue.
 * @param value The value to add to the queue.
 * @return true if successful, or false if the queue is full or memory
 * allocation fails.
 */
bool enqueue(NeuQueue *queue, int value) {
  if (is_queue_full(queue)) {
    errno = ENOSPC;
    return false;
  }
  errno = 0;
  queue->data[queue->end] = value;
  queue->end = (queue->end + 1) % queue->capacity;
  queue->size++;

  return true;
}

/**
 * Checks if the queue is empty.
 *
 * @param queue A pointer to the queue.
 * @return true if the queue is empty, false otherwise.
 */
bool is_queue_empty(NeuQueue *queue) {
  return queue->size == 0;
}

/**
 * Checks if the queue is full.
 *
 * @param queue A pointer to the queue.
 * @return true if the queue is full, false otherwise.
 */
bool is_queue_full(NeuQueue *queue) {
  return queue->size == queue->capacity;
}

/**
 * Gets the current capacity of the queue.
 *
 * @param queue A pointer to the queue.
 * @return The capacity of the queue.
 */
int get_queue_capacity(NeuQueue *queue) {
  return queue->capacity;
}

/**
 * Gets the current size of the queue.
 *
 * @param queue A pointer to the queue.
 * @return The number of elements in the queue.
 */
int get_queue_size(NeuQueue *queue) {
  return queue->size;
}

/**
 * Gets the front element of the queue without removing it.
 *
 * @param queue A pointer to the queue.
 * @return The value of the front element, or -1 if the queue is empty.
 */
int peek_queue(NeuQueue *queue) {
  if (is_queue_empty(queue)){
    return -1;
  }
  return queue->data[queue->front];
}

/**
 * Prints the elements of the queue to the standard output.
 *
 * @param queue A pointer to the queue.
 */
void print_queue(NeuQueue *queue) {
  if (queue == NULL) {
    printf("Queue is NULL\n");
    return;
  }

  printf("Queue: [");
  for (size_t i = 0; i < queue->size; i++) {
    size_t index = (queue->front + i) % queue->capacity;
    printf("%d", queue->data[index]);
    if (i < queue->size - 1) {
      printf(", "); // Only print comma if not the last element
    }
  }
  printf("]\n");
}

void print_queue_memory(NeuQueue *queue) {
  if (queue == NULL) {
    printf("Queue is NULL\n");
    return;
  }
  printf("Queue memory locations: [");
  for (int i = 0; i < queue->capacity; i++) {
    // Check if the index is within the valid range of the circular queue
    if (queue->size > 0 &&
        ((queue->front <= queue->end && i >= queue->front && i < queue->end) ||
         (queue->front >= queue->end &&
          (i >= queue->front || i < queue->end)))) {
      printf("%d", queue->data[i]); // Print the value at the valid index
    } else {
      printf("_"); // Print an underscore for invalid indices
    }
    if (i < queue->capacity - 1) {
      printf(", "); // Only print comma if not the last element
    }
  }
  printf("]\n");
}

/**
 * Converts the queue to a string representation.
 *
 * @param queue A pointer to the queue.
 * @return A string representation of the queue, or NULL if memory allocation
 * fails.
 */
const char *queue_to_string(NeuQueue *queue) {
  // Return NULL if queue is NULL
  if (queue == NULL) {
    return NULL;
  }

  // Allocate memory for string representation
  // Size calculation: [, ] + commas + each number (max 11 chars per int) + null
  // terminator
  size_t max_size =
      2 + (queue->size > 0 ? queue->size - 1 : 0) + (queue->size * 12) + 1;
  char *result = (char *)malloc(max_size * sizeof(char));
  if (result == NULL) {
    return NULL;
  }

  // Start with an opening bracket
  strcpy(result, "[");

  // If queue is not empty, add elements
  if (!is_queue_empty(queue)) {
    size_t current_pos = queue->front;

    for (size_t i = 0; i < queue->size; i++) {
      // Add current element
      char temp[12]; // Enough for any int value
      sprintf(temp, "%d", queue->data[current_pos]);
      strcat(result, temp);

      // Add comma if not the last element
      if (i < queue->size - 1) {
        strcat(result, ", ");
      }

      // Move to next position (circular)
      current_pos = (current_pos + 1) % queue->capacity;
    }
  }

  // Close with ending bracket
  strcat(result, "]");

  return result;
=======
/**
 * Starter code for Code Along - NeuQueue (circular queue)
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "NeuQueue.h"

/**
 * Creates a new queue with the specified initial capacity.
 *
 * @param initial_capacity The initial capacity of the queue.
 * @return A pointer to the newly created queue, or NULL if memory allocation
 * fails.
 */
NeuQueue *create_queue(size_t initial_capacity) {
  // TODO: Implement this function
  return NULL;
}

/**
 * Frees the memory allocated for the queue.
 *
 * @param queue A pointer to the queue to be freed.
 */
void free_queue(NeuQueue *queue) {
  // TODO: Implement this function
}

/**
 * Removes and returns the front element of the queue.
 *
 * @param queue A pointer to the queue.
 * @return The value of the removed element, or -1 if the queue is empty.
 */
int dequeue(NeuQueue *queue) {
  // TODO: Implement this function
  return -1;
}

/**
 * Adds an element to the end of the queue.
 *
 * @param queue A pointer to the queue.
 * @param value The value to add to the queue.
 * @return true if successful, or false if the queue is full or memory
 * allocation fails.
 */
bool enqueue(NeuQueue *queue, int value) {
  // TODO: Implement this function
  return false;
}

/**
 * Checks if the queue is empty.
 *
 * @param queue A pointer to the queue.
 * @return true if the queue is empty, false otherwise.
 */
bool is_queue_empty(NeuQueue *queue) {
  // TODO: Implement this function
  return true;
}

/**
 * Checks if the queue is full.
 *
 * @param queue A pointer to the queue.
 * @return true if the queue is full, false otherwise.
 */
bool is_queue_full(NeuQueue *queue) {
  // TODO: Implement this function
  return false;
}

/**
 * Gets the current capacity of the queue.
 *
 * @param queue A pointer to the queue.
 * @return The capacity of the queue.
 */
int get_queue_capacity(NeuQueue *queue) {
  // TODO: Implement this function
  return 0;
}

/**
 * Gets the current size of the queue.
 *
 * @param queue A pointer to the queue.
 * @return The number of elements in the queue.
 */
int get_queue_size(NeuQueue *queue) {
  // TODO: Implement this function
  return 0;
}

/**
 * Gets the front element of the queue without removing it.
 *
 * @param queue A pointer to the queue.
 * @return The value of the front element, or -1 if the queue is empty.
 */
int peek_queue(NeuQueue *queue) {
  // TODO: Implement this function
  return -1;
}

/**
 * Prints the elements of the queue to the standard output.
 *
 * @param queue A pointer to the queue.
 */
void print_queue(NeuQueue *queue) {
  if (queue == NULL) {
    printf("Queue is NULL\n");
    return;
  }

  printf("Queue: [");
  for (size_t i = 0; i < queue->size; i++) {
    size_t index = (queue->front + i) % queue->capacity;
    printf("%d", queue->data[index]);
    if (i < queue->size - 1) {
      printf(", "); // Only print comma if not the last element
    }
  }
  printf("]\n");
}

void print_queue_memory(NeuQueue *queue) {
  if (queue == NULL) {
    printf("Queue is NULL\n");
    return;
  }
  printf("Queue memory locations: [");
  for (int i = 0; i < queue->capacity; i++) {
    // Check if the index is within the valid range of the circular queue
    if (queue->size > 0 &&
        ((queue->front <= queue->end && i >= queue->front && i < queue->end) ||
         (queue->front >= queue->end &&
          (i >= queue->front || i < queue->end)))) {
      printf("%d", queue->data[i]); // Print the value at the valid index
    } else {
      printf("_"); // Print an underscore for invalid indices
    }
    if (i < queue->capacity - 1) {
      printf(", "); // Only print comma if not the last element
    }
  }
  printf("]\n");
}

/**
 * Converts the queue to a string representation.
 *
 * @param queue A pointer to the queue.
 * @return A string representation of the queue, or NULL if memory allocation
 * fails.
 */
const char *queue_to_string(NeuQueue *queue) {
  // Return NULL if queue is NULL
  if (queue == NULL) {
    return NULL;
  }

  // Allocate memory for string representation
  // Size calculation: [, ] + commas + each number (max 11 chars per int) + null
  // terminator
  size_t max_size =
      2 + (queue->size > 0 ? queue->size - 1 : 0) + (queue->size * 12) + 1;
  char *result = (char *)malloc(max_size * sizeof(char));
  if (result == NULL) {
    return NULL;
  }

  // Start with an opening bracket
  strcpy(result, "[");

  // If queue is not empty, add elements
  if (!is_queue_empty(queue)) {
    size_t current_pos = queue->front;

    for (size_t i = 0; i < queue->size; i++) {
      // Add current element
      char temp[12]; // Enough for any int value
      sprintf(temp, "%d", queue->data[current_pos]);
      strcat(result, temp);

      // Add comma if not the last element
      if (i < queue->size - 1) {
        strcat(result, ", ");
      }

      // Move to next position (circular)
      current_pos = (current_pos + 1) % queue->capacity;
    }
  }

  // Close with ending bracket
  strcat(result, "]");

  return result;
>>>>>>> 65b7a049082a4b605d709c3dd680905dc1b962d6
}