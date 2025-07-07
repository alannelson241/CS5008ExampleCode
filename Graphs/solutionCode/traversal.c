/**
  * Solution Code for Graph Traversal
 */

#include <stdio.h>
#include <stdlib.h>
#include "traversal.h"
#include "adjList.h"
#include "debug.h"

/**
 * Performs Depth-First Search traversal on the graph
 * @param graph Pointer to the graph
 * @param startVertex Starting vertex for the traversal
 */
void DFS(AdjListGraph* graph, int startVertex, TraversalInfo* info) {
    if(graph == NULL || info == NULL) {
        fprintf(stderr, "Graph or info is NULL.\n");
        return;
    }
    
    // Initialize all vertices
    for(int i = 0; i < graph->numVertices; i++) {
        info[i].visited = false;
        info[i].previous = -1;
        info[i].discovery = -1;
        info[i].finish = -1;
    }
    
    // Create a stack for DFS
    int stack[graph->numVertices];
    int top = -1;
    int time = 0;
    
    // Push the start vertex
    stack[++top] = startVertex;
    info[startVertex].discovery = time++;
    info[startVertex].visited = true;
    
    while(top >= 0) {
        int currentVertex = stack[top];
        AdjListNode* currentNode = graph->adjList[currentVertex];
        
        // Find an unvisited adjacent vertex
        while(currentNode != NULL && 
              (info[currentNode->vertex].visited || currentNode->vertex < 0)) {
            currentNode = currentNode->next;
        }
        
        if(currentNode != NULL) {
            // Found unvisited neighbor, push to stack
            info[currentNode->vertex].visited = true;
            info[currentNode->vertex].discovery = time++;
            info[currentNode->vertex].previous = currentVertex;
            stack[++top] = currentNode->vertex;
            DEBUG_PRINT(DEBUG_INFO, "Visited vertex %d from vertex %d\n", 
                       currentNode->vertex, currentVertex);
        } else {
            // No more unvisited neighbors, pop and set finish time
            top--;
            info[currentVertex].finish = time++;
            DEBUG_PRINT(DEBUG_INFO, "Finished vertex %d\n", currentVertex);
        }
    }
}

/**
 * Performs Breadth-First Search traversal on the graph
 * @param graph Pointer to the graph
 * @param startVertex Starting vertex for the traversal
 */
void BFS(AdjListGraph* graph, int startVertex, TraversalInfo* info) {
    if(graph == NULL || info == NULL) {
        fprintf(stderr, "Graph or info is NULL.\n");
        return;
    }
    for(int i = 0; i < graph->numVertices; i++) {
        info[i].visited = false;
        info[i].previous = -1;
        info[i].distance = -1;
    }
    info[startVertex].visited = true;
    info[startVertex].distance = 0;
    info[startVertex].previous = -1;
    int queue[graph->numVertices];
    int front = 0, rear = 0;
    queue[rear++] = startVertex;
    while (front < rear) {
        int currentVertex = queue[front++];
        AdjListNode* currentNode = graph->adjList[currentVertex];
        while (currentNode != NULL) {
            if (!info[currentNode->vertex].visited) {
                info[currentNode->vertex].visited = true;
                info[currentNode->vertex].distance = info[currentVertex].distance + 1;
                info[currentNode->vertex].previous = currentVertex;
                queue[rear++] = currentNode->vertex;
                DEBUG_PRINT(DEBUG_INFO, "Visited vertex %d from vertex %d\n", currentNode->vertex, currentVertex);
            }
            currentNode = currentNode->next;
        }
    }
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