/**
* Starter code for the code along on Priority Queue
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "NeuPriorityQueue.h"


/**
 * Creates a new priority queue with the given capacity.
 * @param capacity The maximum number of elements the queue can hold.
 * @return A pointer to the newly created priority queue.
 */
NeuPriorityQueue* create_priority_queue(int capacity) {
    NeuPriorityQueue* queue = (NeuPriorityQueue*)malloc(sizeof(NeuPriorityQueue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    queue->data = (int*)malloc(sizeof(int) * capacity);
    if (queue->data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

/**
 * Frees the memory allocated for the priority queue.
 * @param queue A pointer to the priority queue to free.
 */
void free_priority_queue(NeuPriorityQueue* queue) {
    if (queue) {
        free(queue->data);
        free(queue);
    }
}

/**
 * Clears all elements from the priority queue.
 * @param queue A pointer to the priority queue to clear.
 */
void clear_priority_queue(NeuPriorityQueue* queue) {
    queue->size = 0;
}

/**
 * Removes and returns the highest-priority element from the queue.
 * @param queue A pointer to the priority queue.
 * @return The value of the highest-priority element.
 */
int dequeue(NeuPriorityQueue* queue) {
    if (!has_items(queue)) {
        fprintf(stderr, "Queue is empty.\n");
        errno = ENODATA;
        return -1;
    }
    errno = 0;
    int highest_priority = queue->data[queue->size-1];
    queue->size --;
    return highest_priority;
}

void __double_queue_capacity(NeuPriorityQueue *queue) {
    int new_capacity = queue->capacity * SCALE_FACTOR;
    int *new_data = (int *)realloc(queue->data, new_capacity *sizeof(int));
    // have null check
    queue->data = new_data;
    queue->capacity = new_capacity;
}

/**
 * Adds a new element to the priority queue.
 * @param queue A pointer to the priority queue.
 * @param value The value to add to the queue.
 */
void enqueue(NeuPriorityQueue* queue, int value) {
    if (queue->size >= queue->capacity) {
        __double_queue_capacity(queue);
    }
    if (queue->size == 0) {
        queue->data[0] = value;
    } else {
        int i = queue->size-1;
        while(i >= 0 && queue->data[i] >= value) {
            queue->data[i + i] = queue->data[i];
            i--;
        }
        queue->data[i + 1] = value;
    }
    queue->size++;
}

/**
 * Checks if the priority queue has any items.
 * @param queue A pointer to the priority queue.
 * @return true if the queue has items, false otherwise.
 */
bool has_items(NeuPriorityQueue* queue) {
    return (queue->size > 0);
}

/**
 * Returns the highest-priority element without removing it.
 * @param queue A pointer to the priority queue.
 * @return The value of the highest-priority element.
 */
int peek(NeuPriorityQueue* queue) {
    // TODO: Implement
    return 0;
}

/**
 * Prints the elements of the priority queue.
 * @param queue A pointer to the priority queue.
 */
void print_priority_queue(NeuPriorityQueue* queue) {
    if (queue == NULL) {
        // print error
        return;
    }
    printf("Priority Queue [");
    for (int i = queue->size - 1; i >= 0; i--) {
        printf("%d", queue->data[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("]\n");
}