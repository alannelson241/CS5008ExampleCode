/**
* Test file for the Sorted Array based Priority Queue
*
*/

#include <stdio.h>
#include <stdlib.h>

#include "NeuPriorityQueue.h"


int enqueu_random_elements(NeuPriorityQueue* queue, int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        enqueue(queue, rand() % 100);
    }
    return 0;
}

int dequeue_elements(NeuPriorityQueue* queue, int num_elements) {
    for (int i = 0; i < num_elements; i++) {
        if (has_items(queue)) {
            printf("Dequeued: %d\n", dequeue(queue));
        } else {
            printf("Queue is empty, cannot dequeue.\n");
            break;
        }
    }
    return 0;
}

void simpleTest() {
    NeuPriorityQueue* queue = create_priority_queue(5);
    if (!queue) {
        exit(EXIT_FAILURE);
    }

    enqueue(queue, 5);
    enqueue(queue, 3);
    enqueue(queue, 8);
    enqueue(queue, 1);
    enqueue(queue, 7);
    enqueue(queue, 2);

    printf("Priority Queue after enqueuing elements:\n");
    print_priority_queue(queue);

    // Implement peak first
    // printf("Peek: %d\n", peek(queue));

    printf("Dequeue: %d\n", dequeue(queue));
    printf("Priority Queue after dequeue:\n");
    print_priority_queue(queue);

    // Clear the queue - implement clear first
    // clear_priority_queue(queue);
    // printf("Priority Queue after clearing:\n");
    // print_priority_queue(queue);

    free_priority_queue(queue);
}

void size_test(int size) {
    NeuPriorityQueue* queue = create_priority_queue(size);
    if (!queue) {
        exit(EXIT_FAILURE);
    }

    enqueu_random_elements(queue, size);
    printf("Priority Queue after enqueuing %d elements:\n", size);
    print_priority_queue(queue);

    dequeue_elements(queue, size);
    printf("Priority Queue after dequeuing %d elements:\n", size);
    print_priority_queue(queue);

    free_priority_queue(queue);
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        int size = atoi(argv[1]);
        if (size <= 0) {
            fprintf(stderr, "Invalid size argument. Using default size of 10.\n");
            size = 10;
        }
        size_test(size);
    } else {
        simpleTest();
    }

    return EXIT_SUCCESS;
}