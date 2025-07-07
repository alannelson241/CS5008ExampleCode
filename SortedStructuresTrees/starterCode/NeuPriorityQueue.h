#ifndef NEU_PRIORITY_QUEUE_H
#define NEU_PRIORITY_QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

#define SCALE_FACTOR 2

typedef struct NeuPriorityQueue {
    int *data;
    int capacity;
    int size;
} NeuPriorityQueue;

NeuPriorityQueue* create_priority_queue(int capacity);
void free_priority_queue(NeuPriorityQueue* queue);
void enqueue(NeuPriorityQueue* queue, int value);
int dequeue(NeuPriorityQueue* queue);
int peek(NeuPriorityQueue* queue);
bool has_items(NeuPriorityQueue* queue);
void clear_priority_queue(NeuPriorityQueue* queue);
void print_priority_queue(NeuPriorityQueue* queue);





#endif // NEU_PRIORITY_QUEUE_H