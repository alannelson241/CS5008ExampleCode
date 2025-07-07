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
    AdjMatrixGraph* graph = (AdjMatrixGraph*)malloc(sizeof(AdjMatrixGraph));
    if (graph == NULL) {
        return NULL;
    }
    graph->numVertices = 0;
    graph->capacity = capacity;
    graph->directed = isDirected;
    graph->adjMatrix = (int*)malloc(capacity * capacity * sizeof(int));
    if (graph->adjMatrix == NULL) {
        free(graph);
        return NULL;
    }
    for (int i = 0; i < capacity * capacity; i++) {
        graph->adjMatrix[i] = DEFAULT_WEIGHTS; // Initialize all weights to 0
    }
    return graph;
}

/**
 * Frees the memory allocated for the adjacency matrix graph.
 * @param graph A pointer to the AdjMatrixGraph to free.
 */
void freeGraph(AdjMatrixGraph* graph) {
    if (graph != NULL) {
        free(graph->adjMatrix);
        free(graph);
    }
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
    if (src < 0 || dest < 0) {
        fprintf(stderr, "Error: Vertex out of bounds\n");
        return;
    }
    // if i have a source and destination that are greater than the current number of vertices
    graph->numVertices = (src >= graph->numVertices) ? src + 1 : graph->numVertices;
    graph->numVertices = (dest >= graph->numVertices) ? dest + 1 : graph->numVertices;
    DEBUG_PRINT(DEBUG_INFO, "Vertex count: %d\n", graph->numVertices);

    if (graph->numVertices >= graph->capacity) {
        __resizeGraph(graph);
    }

    graph->adjMatrix[src * graph->capacity + dest] = weight;
    if(graph->directed == false) graph->adjMatrix[dest * graph->capacity + src] = weight; // For undirected graph
}

/**
 * Gets the degree (number of neighbors) of a vertex.
 * @param graph A pointer to the AdjMatrixGraph.
 * @param vertex The vertex to get the degree of.
 * @return The degree of the vertex.
 */
int getDegree(AdjMatrixGraph* graph, int vertex) {
    if (vertex < 0 || vertex >= graph->numVertices) {
        fprintf(stderr, "Error: Vertex out of bounds\n");
        return -1;
    }
    int degree = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex * graph->capacity + i] != DEFAULT_WEIGHTS) {
            degree++;
        }
    }
    return degree;
}

/**
 * Gets the neighbors of a vertex.
 * @param graph A pointer to the AdjMatrixGraph.
 * @param vertex The vertex to get neighbors for.
 * @return A pointer to an array of neighbor vertex indices (caller must free).
 */
int* getNeighbors(AdjMatrixGraph* graph, int vertex) {
    if (vertex < 0 || vertex >= graph->numVertices) {
        fprintf(stderr, "Error: Vertex out of bounds\n");
        return NULL;
    }
    int* neighbors = (int*)malloc(graph->numVertices * sizeof(int));
    if (neighbors == NULL) {
        return NULL; // Handle memory allocation failure
    }
    int count = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex * graph->capacity + i] != DEFAULT_WEIGHTS) {
            neighbors[count++] = i;
        }
    }
    neighbors[count] = -1; // Mark end of neighbors
    return neighbors;
}

/**
 * Gets the weight of the edge from src to dest.
 * @param graph A pointer to the AdjMatrixGraph.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @return The weight of the edge, or 0 if no edge exists.
 */
int getWeight(AdjMatrixGraph* graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->numVertices || dest >= graph->numVertices) {
        fprintf(stderr, "Error: Vertex out of bounds\n");
        return 0;
    }
    return graph->adjMatrix[src * graph->capacity + dest];
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
    GraphReader* reader = reader_open(filename);
    if (reader == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }
    int src, dest, weight;
    int* line;
    while ((line = reader_next(reader)) != NULL) {
        src = line[0];
        dest = line[1];
        weight = line[2];
        DEBUG_PRINT(DEBUG_INFO, "Adding edge from %d to %d with weight %d\n", src, dest, weight);
        addEdge(graph, src, dest, weight);
    }
    reader_close(reader);
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