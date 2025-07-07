/**
  * Solution Code for Graph Traversal
 */

#include "traversal.h"

/**
 * Performs Depth-First Search traversal on the graph
 * @param graph Pointer to the graph
 * @param startVertex Starting vertex for the traversal
 */
void DFS(AdjListGraph* graph, int startVertex, TraversalInfo* info) {
    //TODO: Implement
}

/**
 * Performs Breadth-First Search traversal on the graph
 * @param graph Pointer to the graph
 * @param startVertex Starting vertex for the traversal
 */
void BFS(AdjListGraph* graph, int startVertex, TraversalInfo* info) {
    //TODO: Implement
}

/**
 * Initializes the traversal table
 * @param graph Pointer to the graph
 * @return Pointer to the initialized traversal table
 */
TraversalTable* initTraversalTable(AdjListGraph* graph) {
    TraversalTable* table = (TraversalTable*)malloc(sizeof(TraversalTable));
    if (table == NULL) {
        fprintf(stderr, "Memory allocation failed for traversal table.\n");
        exit(EXIT_FAILURE);
    }
    table->numVertices = graph->numVertices;
    table->info = (TraversalInfo*)malloc(graph->numVertices * sizeof(TraversalInfo));
    if (table->info == NULL) {
        fprintf(stderr, "Memory allocation failed for traversal info.\n");
        free(table);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < graph->numVertices; i++) {
        table->info[i].visited = false;
        table->info[i].previous = -1;
        table->info[i].distance = -1;
        table->info[i].discovery = -1;
        table->info[i].finish = -1;
    }
    return table;
}

/**
 * Frees the memory allocated for the traversal table
 * @param table Pointer to the traversal table
 */
void freeTraversalTable(TraversalTable* table) {
    if (table != NULL) {
        free(table->info);
        free(table);
    }
    table = NULL;
}

/**
 * Prints the traversal information, varies columns by traversal type
 * @param table Pointer to the traversal table
 * @param isDFS Boolean indicating if the traversal is DFS or BFS
 */
void printTraversalInfo(TraversalTable* table, bool isDFS) {
    if (isDFS) {
        printf("DFS Traversal:\n");
        printf("Vertex  Discovery  Finish  Previous\n");
        for (int i = 0; i < table->numVertices; i++) {
            printf("%-7d %-10d %-7d %-8d\n", i, table->info[i].discovery, table->info[i].finish, table->info[i].previous);
        }
    } else {
        printf("BFS Traversal:\n");
        printf("Vertex  Distance  Previous\n");
        for (int i = 0; i < table->numVertices; i++) {
            printf("%-7d %-9d %-8d\n", i, table->info[i].distance, table->info[i].previous);
        }
    }
}