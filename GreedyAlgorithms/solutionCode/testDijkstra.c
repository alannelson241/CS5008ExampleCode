/**
 * Tests for Dijkstra's algorithm implementation.
 */


#include <stdio.h>
#include <stdlib.h>

#include "adjList.h"
#include "debug.h"
#include "dijkstra.h"



int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <graph_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if(argc > 2) {
        set_debug_level(atoi(argv[2]));
    }

    // Read the graph from the file
    AdjListGraph * graph = createGraph(10000, true);
    if (graph == NULL) {
        fprintf(stderr, "Failed to create graph\n");
        return EXIT_FAILURE;
    }
    loadFromFile(graph, argv[1]);
    DEBUG_PRINT(DEBUG_INFO, "Loaded graph with %d vertices\n", graph->numVertices);

    int dist[graph->numVertices];
    int prev[graph->numVertices];

    dijkstra(graph, 0, dist, prev);

    // Print the shortest path from source to all vertices
    printSolution(dist, prev, graph->numVertices);


}