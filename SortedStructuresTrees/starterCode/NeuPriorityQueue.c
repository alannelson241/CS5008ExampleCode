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
    //TODO: Implement
}

/**
 * Frees the memory allocated for the priority queue.
 * @param queue A pointer to the priority queue to free.
 */
void free_priority_queue(NeuPriorityQueue* queue) {
    // TODO: Implement
}

/**
 * Clears all elements from the priority queue.
 * @param queue A pointer to the priority queue to clear.
 */
void clear_priority_queue(NeuPriorityQueue* queue) {
    // TODO: Implement
}

/**
 * Removes and returns the highest-priority element from the queue.
 * @param queue A pointer to the priority queue.
 * @return The value of the highest-priority element.
 */
int dequeue(NeuPriorityQueue* queue) {
    // TODO: Implement
    return 0;
}

/**
 * Adds a new element to the priority queue.
 * @param queue A pointer to the priority queue.
 * @param value The value to add to the queue.
 */
void enqueue(NeuPriorityQueue* queue, int value) {
    // TODO: Implement
}

/**
 * Checks if the priority queue has any items.
 * @param queue A pointer to the priority queue.
 * @return true if the queue has items, false otherwise.
 */
bool has_items(NeuPriorityQueue* queue) {
    // TODO: Implement
    return false;
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
    // TODO: Implement
}