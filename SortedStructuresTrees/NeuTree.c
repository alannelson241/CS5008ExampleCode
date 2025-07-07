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
    NeuTree *tree = (NeuTree*)malloc(sizeof(NeuTree));
    if (!tree) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void __free_tree_nodes(NeuNode *node) {
    if (node == NULL) {
        return;
    }
    __free_tree_nodes(node->left);
    __free_tree_nodes(node->right);
    free(node);
}

/**
 * Frees the memory allocated for the tree.
 * @param tree A pointer to the tree to free.
 */
void free_tree(NeuTree* tree) {
    if (tree == NULL) {
        return;
    }
    __free_tree_nodes(tree->root);
    free(tree);
}

/**
 * Adds a new node with the given data to the tree.
 * @param tree A pointer to the tree.
 * @param data The data to add to the tree.
 */
void add(NeuTree* tree, char data) {
    NeuNode *new_node = (NeuNode*)malloc(sizeof(NeuNode));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        NeuNode* current = tree->root;
        NeuNode* parent = NULL;
        while (current != NULL) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (data < parent->data) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }
    tree->size++;
}

/**
 * Performs a breadth-first traversal of the tree.
 * @param tree A pointer to the tree.
 * @param visit A function pointer to apply to each node's data.
 */
void breadth_first_traversal(NeuTree* tree, void (*visit)(char)) {
    // null check for tree and root

    NeuNode* queue[tree->size];
    int front = 0;
    int rear = 0;

    queue[rear++] = tree->root;

    while(front < rear) {
        NeuNode* current = queue[front++];
        visit(current->data);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

void __preorder(NeuNode* node, void (*visit)(char)) {
    if (node == NULL) {
        return;
    }
    visit(node->data);
    __preorder(node->left, visit);
    __preorder(node->right, visit);
}

void __inorder(NeuNode* node, void (*visit)(char)) {
    if (node == NULL) {
        return;
    }
    __inorder(node->left, visit);
    visit(node->data);
    __inorder(node->right, visit);
}

void __postorder(NeuNode* node, void (*visit)(char)) {
    if (node == NULL) {
        return;
    }
    __postorder(node->left, visit);
    __postorder(node->right, visit);
    visit(node->data);
}

/**
 * Performs a depth-first traversal of the tree.
 * @param tree A pointer to the tree.
 * @param type The type of depth-first traversal (PRE_ORDER, IN_ORDER, POST_ORDER).
 * @param visit A function pointer to apply to each node's data.
 */
void depth_first_traversal(NeuTree* tree, enum TraversalType type, void (*visit)(char)) {
    // null check
    switch (type) {
        case PRE_ORDER:
            __preorder(tree->root, visit);
            break;
        case IN_ORDER:
            __inorder(tree->root, visit);
            break;
        case POST_ORDER:
            __postorder(tree->root, visit);
            break;
        default:
            // error
            exit(EXIT_FAILURE);
    }
}