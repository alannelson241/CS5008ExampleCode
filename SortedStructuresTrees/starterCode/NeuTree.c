/**
 * Starter Code for Code Along Tree Traversal
 */


#include <stdio.h>
#include <stdlib.h>

#include "NeuTree.h"

/**
 * Creates a new tree.
 * @return A pointer to the newly created tree.
 */
NeuTree* create_tree() {
    // TODO: Implement
    return NULL;
}

/**
 * Frees the memory allocated for the tree.
 * @param tree A pointer to the tree to free.
 */
void free_tree(NeuTree* tree) {
    // TODO: Implement
}

/**
 * Adds a new node with the given data to the tree.
 * @param tree A pointer to the tree.
 * @param data The data to add to the tree.
 */
void add(NeuTree* tree, char data) {
    // TODO: Implement
}

/**
 * Performs a breadth-first traversal of the tree.
 * @param tree A pointer to the tree.
 * @param visit A function pointer to apply to each node's data.
 */
void breadth_first_traversal(NeuTree* tree, void (*visit)(char)) {
    // TODO: Implement
}

/**
 * Performs a depth-first traversal of the tree.
 * @param tree A pointer to the tree.
 * @param type The type of depth-first traversal (PRE_ORDER, IN_ORDER, POST_ORDER).
 * @param visit A function pointer to apply to each node's data.
 */
void depth_first_traversal(NeuTree* tree, enum TraversalType type, void (*visit)(char)) {
    // TODO: Implement
}