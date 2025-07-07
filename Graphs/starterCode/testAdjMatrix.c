/**
 *  File to test the adjacency matrix implementation
 *  of a graph.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "adjMatrix.h"
#include "debug.h"

void getDegreesAndTime(AdjMatrixGraph *graph) {
  clock_t start = clock();
  for (int i = 0; i < graph->numVertices; i++) {
    int degree = getDegree(graph, i);
    DEBUG_PRINT(DEBUG_INFO, "Degree of vertex %d: %d\n", i, degree);
  }
  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time taken to get degrees: %f seconds\n", time_spent);
}

void getWeightAndTime(AdjMatrixGraph *graph) {
  clock_t start = clock();
  for (int i = 0; i < graph->numVertices; i++) {
    int src = rand() % graph->numVertices;
    int weight = getWeight(graph, src, i);
    DEBUG_PRINT(DEBUG_INFO, "Weight of edge from %d to %d: %d\n", src, i, weight);
  }
  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time taken to get weight: %f seconds\n", time_spent);
}

void loadAndTime(AdjMatrixGraph *graph, const char *filename) {
  clock_t start = clock();
  loadFromFile(graph, filename);
  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time taken to load graph: %f seconds\n", time_spent);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }
  if (argc > 2) {
    set_debug_level(atoi(argv[2]));
  }

  const char *filename = argv[1];
  AdjMatrixGraph *graph = createGraph(10000, true);
  if (graph == NULL) {
    fprintf(stderr, "Failed to create graph\n");
    return EXIT_FAILURE;
  }

  loadAndTime(graph, filename);
  printf("Graph loaded with %d vertices\n", graph->numVertices);
  getDegreesAndTime(graph);
  getWeightAndTime(graph);

  if (graph->numVertices < 30) {
    printGraph(graph);
  }

  freeGraph(graph);
  return EXIT_SUCCESS;
}
