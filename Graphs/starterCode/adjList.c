/**
* Solution Code for Adjacency Matrix Representation of Graph Code Along
* @author Albert Lionelle
* @date 2025-05-20
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "adjList.h"
#include "debug.h"
#include "GraphReader.h"



#include "adjList.h"

/**
 * Creates a new adjacency list graph with the given capacity.
 * @param capacity The initial capacity (number of vertices) of the graph.
 * @param directed Whether the graph is directed (true) or undirected (false).
 * @return A pointer to the newly created AdjListGraph.
 */
AdjListGraph* createGraph(int capacity, bool directed) {
    //TODO: Implementation
    return NULL;
}

/**
 * Frees the memory allocated for the adjacency list graph.
 * @param graph A pointer to the AdjListGraph to free.
 */
void freeGraph(AdjListGraph* graph) {
    //TODO: Implementation
}

/**
 * Doubles the capacity of the graph's adjacency list.
 * @param graph A pointer to the AdjListGraph.
 */
void __resizeGraph(AdjListGraph* graph) {
     DEBUG_PRINT(DEBUG_INFO, "Resizing graph from %d to %d\n", graph->capacity, graph->capacity * SCALE_FACTOR);
    int newCapacity = graph->capacity * SCALE_FACTOR;
    AdjListNode** newAdjList = (AdjListNode**)malloc(newCapacity * sizeof(AdjListNode*));
    if (newAdjList == NULL) {
        fprintf(stderr, "Memory allocation failed while doubling capacity.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < newCapacity; i++) {
        newAdjList[i] = NULL;
    }
    for (int i = 0; i < graph->capacity; i++) {
        newAdjList[i] = graph->adjList[i];
    }
    free(graph->adjList);
    graph->adjList = newAdjList;
    graph->capacity = newCapacity;
}

/**
 * Adds an edge to the graph from src to dest with the given weight.
 * @param graph A pointer to the AdjListGraph.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @param weight The weight of the edge.
 */
void addEdge(AdjListGraph* graph, int src, int dest, int weight) {
    //TODO: Implementation
}

/**
 * Gets the degree (number of neighbors) of a vertex.
 * @param graph A pointer to the AdjListGraph.
 * @param vertex The vertex to get the degree of.
 * @return The degree of the vertex.
 */
int getDegree(AdjListGraph* graph, int vertex) {
    //TODO: Implementation
    return 0;
}

/**
 * Gets the neighbors of a vertex.
 * @param graph A pointer to the AdjListGraph.
 * @param vertex The vertex to get neighbors for.
 * @return A pointer to an array of neighbor vertex indices (caller must free).
 */
int* getNeighbors(AdjListGraph* graph, int vertex) {
    //TODO: Implementation
    return NULL;
}

/**
 * Gets the weight of the edge from src to dest.
 * @param graph A pointer to the AdjListGraph.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @return The weight of the edge, or 0 if no edge exists.
 */
int getWeight(AdjListGraph* graph, int src, int dest) {
    //TODO: Implementation
    return 0;
}

/**
 * Prints the adjacency list of the graph.
 * Prints in the format of "Vertex: [(neighbor1, weight1), (neighbor2, weight2), ...]"
 * @param graph A pointer to the AdjListGraph.
 */
void printGraph(AdjListGraph* graph) {
   for(int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        printf("[");
        AdjListNode* current = graph->adjList[i];
        while (current != NULL) {
            printf("(%d, %d)", current->vertex, current->weight);
            current = current->next;
            if (current != NULL) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

/**
 * Loads a graph from a file.
 * @param graph A pointer to the AdjListGraph.
 * @param filename The name of the file to load from.
 */
void loadFromFile(AdjListGraph* graph, const char* filename) {
    //TODO: Implementation
}