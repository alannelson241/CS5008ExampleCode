/**
* Test file for code along tree traversal. 
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "NeuTree.h"


void print_node(char data) {
    printf("%c ", data);
}



/**
 * Examples of interesting string inputs:
 * - "aloha" - creates an unbalanced tree with nodes in a zigzag pattern
 * - "abcdefg" - creates a completely right-skewed tree
 * - "gfedcba" - creates a completely left-skewed tree
 * - "dbacfeg" - creates a more balanced tree
 * - "breadth" - creates a tree with multiple levels and branches
 * Examples with tree structures:
 * 
 * "aloha":
 *         a
 *          \
 *           l
 *          / \
 *         h   o
 *        /
 *       a 
 *
 * "abcdefg":
 *        a
 *         \
 *          b
 *           \
 *            c
 *             \
 *              d
 *               \
 *                e
 *                 \
 *                  f
 *                   \
 *                    g
 *
 * "gfedcba":
 *        g
 *       /
 *      f
 *     /
 *    e
 *   /
 *  d
 * /
 * c
 
 * "dbacfeg":
 *        d
 *       / \
 *      b   f
 *     / \   \
 *    a   c   e
 *             \
 *              g
 *
 * "breadth":
 *        b
 *       / \
 *      a   r
 *         / \
 *        e   t
 *       /     \
 *      d       h
 */


int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // Create a new tree
    NeuTree* tree = create_tree();

    int i = 0;
    while(argv[1][i] != '\0') {
        add(tree, argv[1][i++]);
    }

    // Perform breadth-first traversal
    printf("Breadth-first traversal:\n");
    breadth_first_traversal(tree, print_node);
    printf("\n");

    // Perform depth-first traversal
    printf("Depth-first traversal (pre-order):\n");
    depth_first_traversal(tree, PRE_ORDER, print_node);
    printf("\n");
    printf("Depth-first traversal (in-order):\n");
    depth_first_traversal(tree, IN_ORDER, print_node);
    printf("\n");
    printf("Depth-first traversal (post-order):\n");
    depth_first_traversal(tree, POST_ORDER, print_node);
    printf("\n");
    // Free the tree
    free_tree(tree);

    return 0;
}