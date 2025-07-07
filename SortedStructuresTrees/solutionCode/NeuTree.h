#ifndef NEUTREE_H
#define NEUTREE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct TNode {
    char data;
    struct TNode *left;
    struct TNode *right;
} NeuNode;

typedef struct NeuTree {
    NeuNode *root;
    int size;
} NeuTree;

enum TraversalType {
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

NeuTree* create_tree();
void free_tree(NeuTree* tree);
void add(NeuTree* tree, char data);
void breadth_first_traversal(NeuTree* tree, void (*visit)(char));
void depth_first_traversal(NeuTree* tree, enum TraversalType type, void (*visit)(char));


#endif // NEUTREE_H