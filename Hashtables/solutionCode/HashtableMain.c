/**
* Test file for the hashtable implementation.
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "NeuHashtable.h"


/**
  * Adds n items to the hashtable with random IDs and names.
  * The IDs and names are generated randomly, as are the prices and quantities.
 */
void randomized_test(NeuHashtable *hashtable, int n) {
    for (int i = 0; i < n; i++) {
        char itemID[10];
        char itemName[20];
        double itemPrice = (double)(rand() % 10000) / 100;
        int itemQuantity = rand() % 100;

        snprintf(itemID, sizeof(itemID), "F%d", i);
        snprintf(itemName, sizeof(itemName), "Item%d", i);

        add_item(hashtable, itemID, itemName, itemPrice, itemQuantity);
    }
}

/**
   * creates a hashtable of the initial capacity and adds items to it to N.
   * times the results of adding items to the hashtable, 
   * prints out the time, visualization of the hashtable, and the load factor.
   * @param argc The number items
 */
void test_hashtable(int n) {
    NeuHashtable *hashtable = create_hashtable(INITIAL_CAPACITY);
    if (hashtable == NULL) {
        fprintf(stderr, "Failed to create hashtable\n");
        return;
    }
    printf("Adding %d items to the hashtable...\n", n);
    
    srand(time(NULL)); // Seed the random number generator
    clock_t start_time = clock();
    randomized_test(hashtable, n);
    clock_t end_time = clock();


    print_table_visual(hashtable);
    printf("Load factor: %.2f\n", get_load_factor(hashtable));
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to add %d items: %.2f seconds\n", n, time_taken);

    free_hashtable(hashtable);
}

void simple_test() {
    // Create a new hashtable
    NeuHashtable* hashtable = create_hashtable(2);
    add_item(hashtable, "F101", "Pineapple", 5.99, 10);
    add_item(hashtable, "F102", "Mango", 3.99, 20);
    add_item(hashtable, "F103", "Banana", 1.99, 30);
    add_item(hashtable, "F104", "Apple", 2.99, 40);

    // Print the hashtable
    printf("Hashtable contents:\n");
    print_hashtable(hashtable);
    print_table_visual(hashtable);
    printf("Load factor: %.2f\n", get_load_factor(hashtable));

    // Free the hashtable
    free_hashtable(hashtable);
    
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        simple_test();
    }
    else {
        int n = atoi(argv[1]);
        if (n <= 0) {
            fprintf(stderr, "Invalid number of items: %s\n", argv[1]);
            return 1;
        }
        test_hashtable(n);
    }

    return 0;
}

