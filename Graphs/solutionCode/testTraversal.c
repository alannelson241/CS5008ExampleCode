/**
 * Test file for testing graph traversal algorithms DFS and BFS
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "adjList.h"
#include "debug.h"
#include "traversal.h"




int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (argc > 2) {
        set_debug_level(atoi(argv[2]));
    }

    const char *filename = argv[1];
    AdjListGraph *graph = createGraph(100, true);
    if (graph == NULL) {
        fprintf(stderr, "Failed to create graph\n");
        return EXIT_FAILURE;
    }

    loadFromFile(graph, filename);
    printf("Graph loaded with %d vertices\n", graph->numVertices);

    TraversalTable* table = initTraversalTable(graph);
    if (table == NULL) {
        fprintf(stderr, "Failed to initialize traversal table\n");
        freeGraph(graph);
        return EXIT_FAILURE;
    }

    int startVertex = 0; // Starting vertex for traversal
    BFS(graph, startVertex, table->info);
    printTraversalInfo(table, false);

    DFS(graph, startVertex, table->info);
    printTraversalInfo(table, true);


    freeTraversalTable(table);
    freeGraph(graph);

    return EXIT_SUCCESS;
}