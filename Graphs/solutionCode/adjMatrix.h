/*
 * adjMatrix.h
 * 
 * Description: Header file for adjacency matrix implementation of a graph
**/

#ifndef ADJ_MATRIX_H
#define ADJ_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct  {
    int numVertices;
    int capacity;
    int* adjMatrix;
    bool directed;
} AdjMatrixGraph;

#define SCALE_FACTOR 2
#define DEFAULT_WEIGHTS 0

AdjMatrixGraph* createGraph(int capacity, bool directed); 
void freeGraph(AdjMatrixGraph* graph);

void addEdge(AdjMatrixGraph* graph, int src, int dest, int weight);
int getDegree(AdjMatrixGraph* graph, int vertex);
int* getNeighbors(AdjMatrixGraph* graph, int vertex);
int getWeight(AdjMatrixGraph* graph, int src, int dest);
void printGraph(AdjMatrixGraph* graph);
void loadFromFile(AdjMatrixGraph* graph, const char* filename);


#endif // ADJ_MATRIX_H