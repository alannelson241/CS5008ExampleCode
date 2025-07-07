/**
* Solution file for Code Along Adjacency Matrix
* 
* @author Albert Lionelle
* @date 2025-05-20
**/


#include <stdio.h>
#include <stdlib.h>

#include "GraphReader.h"
#include "adjMatrix.h"
#include "debug.h"



/**
 * Creates a new adjacency matrix graph with the given capacity.
 * @param capacity The initial capacity (number of vertices) of the graph.
 * @param isDirected A boolean indicating if the graph is directed.
 * @return A pointer to the newly created AdjMatrixGraph.
 */
AdjMatrixGraph* createGraph(int capacity, bool isDirected) {
    //TODO: Implement
    return NULL;
}

/**
 * Frees the memory allocated for the adjacency matrix graph.
 * @param graph A pointer to the AdjMatrixGraph to free.
 */
void freeGraph(AdjMatrixGraph* graph) {
    //TODO: Implement
}

/**
  * Resizes the adjacency matrix to accommodate more vertices.
  * @param graph A pointer to the AdjMatrixGraph.
**/
void __resizeGraph(AdjMatrixGraph* graph) {
    DEBUG_PRINT(DEBUG_INFO, "Resizing graph from %d to %d\n", graph->capacity, graph->capacity * SCALE_FACTOR);
    int newCapacity = graph->capacity * SCALE_FACTOR;
    int* newAdjMatrix = (int*)malloc(newCapacity * newCapacity * sizeof(int));
    if (newAdjMatrix == NULL) {
        return; // Handle memory allocation failure
    }
    for (int i = 0; i < newCapacity * newCapacity; i++) {
        newAdjMatrix[i] = DEFAULT_WEIGHTS; // Initialize all weights to 0
    }
    for (int i = 0; i < graph->capacity; i++) {
        for (int j = 0; j < graph->capacity; j++) {
            newAdjMatrix[i * newCapacity + j] = graph->adjMatrix[i * graph->capacity + j];
        }
    }
    free(graph->adjMatrix);
    graph->adjMatrix = newAdjMatrix;
    graph->capacity = newCapacity;
}

/**
 * Adds an edge to the graph from src to dest with the given weight.
 * @param graph A pointer to the AdjMatrixGraph.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @param weight The weight of the edge.
 */
void addEdge(AdjMatrixGraph* graph, int src, int dest, int weight) {
    //TODO: Implement
}

/**
 * Gets the degree (number of neighbors) of a vertex.
 * @param graph A pointer to the AdjMatrixGraph.
 * @param vertex The vertex to get the degree of.
 * @return The degree of the vertex.
 */
int getDegree(AdjMatrixGraph* graph, int vertex) {
    //TODO: Implement
    return 0;
}

/**
 * Gets the neighbors of a vertex.
 * @param graph A pointer to the AdjMatrixGraph.
 * @param vertex The vertex to get neighbors for.
 * @return A pointer to an array of neighbor vertex indices (caller must free).
 */
int* getNeighbors(AdjMatrixGraph* graph, int vertex) {
    //TODO: Implement
    return NULL;
}

/**
 * Gets the weight of the edge from src to dest.
 * @param graph A pointer to the AdjMatrixGraph.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @return The weight of the edge, or 0 if no edge exists.
 */
int getWeight(AdjMatrixGraph* graph, int src, int dest) {
    //TODO: Implement
    return 0;
}

/**
 * Loads a graph from a file.
 * Assumes file format is:
 * <vertex1> <vertex2> <weight>
 * Each line represents an edge.
 * @param graph A pointer to the AdjMatrixGraph.
 * @param filename The name of the file to load the graph from.    
 */
void loadFromFile(AdjMatrixGraph* graph, const char* filename) {
    //TODO: Implement
}


/**
 * Prints the adjacency matrix of the graph.
 * @param graph A pointer to the AdjMatrixGraph.
 */
void printGraph(AdjMatrixGraph* graph) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < graph->numVertices; i++) {
        printf("[");
        for(int j = 0; j < graph->numVertices; j++) {
            printf("%d", graph->adjMatrix[i * graph->capacity + j]);
            if (j < graph->numVertices - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}