/**
 * @file traversal.h
 * @brief Graph traversal algorithms header file
 */

#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <stdlib.h>
#include <stdbool.h>
#include "adjList.h"

// table to hold traversal information
typedef struct {
    int vertex;
    bool visited;
    int previous;
    // for BFS
    int distance;
    // for DFS
    int discovery;
    int finish;
} TraversalInfo;


typedef struct {
    TraversalInfo* info;
    int numVertices;
} TraversalTable;

/**
 * @brief Performs Depth-First Search traversal on the graph
 * @param graph Pointer to the graph
 * @param startVertex Starting vertex for the traversal
 */
void DFS(AdjListGraph* graph, int startVertex, TraversalInfo* info);

/**
 * @brief Performs Breadth-First Search traversal on the graph
 * @param graph Pointer to the graph
 * @param startVertex Starting vertex for the traversal
 */
void BFS(AdjListGraph* graph, int startVertex, TraversalInfo* info);


/**
 * @brief Initializes the traversal table
 * @param graph Pointer to the graph
 * @return Pointer to the initialized traversal table
 */
TraversalTable* initTraversalTable(AdjListGraph* graph);

/**
 * @brief Frees the memory allocated for the traversal table
 * @param table Pointer to the traversal table
 */
void freeTraversalTable(TraversalTable* table);

/**
 * @brief Prints the traversal information, varies columns by traversal type
 * @param isDFS Boolean indicating if the traversal is DFS or BFS
 * @param table Pointer to the traversal table
 */
void printTraversalInfo(TraversalTable* table, bool isDFS);

#endif /* TRAVERSAL_H */