/**
 *  Starter code for the NeuHashtable implementation.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NeuHashtable.h"

/**
 * Creates a new hashtable with the given capacity.
 * For the capacity, it will find the nearest power of two greater than or equal
 * to the given capacity.
 *
 * @param capacity The initial capacity of the hashtable.
 * @return A pointer to the newly created hashtable.
 */
NeuHashtable *create_hashtable(int capacity) {
  // TODO: Implement
  return NULL;
}

/**
 * Frees the memory allocated for the hashtable.
 * @param hashtable A pointer to the hashtable to free.
 */
void free_hashtable(NeuHashtable *hashtable) {
  // TODO: Implement
}

/**
 * Adds an item to the hashtable.
 * @param hashtable A pointer to the hashtable.
 * @param itemID The ID of the item.
 * @param itemName The name of the item.
 * @param itemPrice The price of the item.
 * @param itemQuantity The quantity of the item.
 */
void add_item(NeuHashtable *hashtable, const char *itemID, const char *itemName,
              double itemPrice, int itemQuantity) {
  // TODO: Implement
}

/**
 * Gets an item from the hashtable by its ID.
 * @param hashtable A pointer to the hashtable.
 * @param itemID The ID of the item to retrieve.
 * @return A pointer to the item if found, or NULL if not found.
 */
Item *get_item(NeuHashtable *hashtable, const char *itemID) {
  // TODO: Implement
  return NULL;
}

/**
 * Gets the load factor of the hashtable.
 * @param hashtable A pointer to the hashtable.
 * @return The load factor of the hashtable.
 */
inline double get_load_factor(NeuHashtable* hashtable) {
    return 0.0; // TODO: Implement
}

/**
 * Removes an item from the hashtable by its ID.
 * @param hashtable A pointer to the hashtable.
 * @param itemID The ID of the item to remove.
 */
void remove_item(NeuHashtable *hashtable, const char *itemID) {
  // TODO: Implement
}

/**
 * Prints an item from the hastable.
 * @param item A pointer to the item to print.
 */
void __print_item(Item *item) {
  if (item != NULL) {
    printf("item(ID: %s, Name: %s, Price: %.2f, Quantity: %d)", item->itemID,
           item->itemName, item->itemPrice, item->itemQuantity);
  } else {
    printf("NULL");
  }
}

/**
 * Prints the contents of the hashtable.
 * Format is key:value seperated by commas.
 * Example: {key1:value1, key2:value2}
 * @param hashtable A pointer to the hashtable.
 */
void print_hashtable(NeuHashtable *hashtable) {
  printf("{");
  for (int i = 0; i < hashtable->capacity; i++) {
    NeuNode *current = hashtable->table[i];
    while (current != NULL) {
      printf("%s:", current->data.itemID);
      __print_item(&current->data);
      current = current->next;
      if (current != NULL) {
        printf(", ");
      }
    }
    if (i < hashtable->capacity - 1 && hashtable->table[i] != NULL) {
      printf(", ");
    }
  }
  printf("}\n");
}

/**
 * Prints the array with a count of number of items in 
 * each index of the hashtable. An example layout would be
 * [1, 0, 0, 0, 0, 0, 0, 1]
 * where the first index has 1 item and the last index has 1 item.
 */
void print_table_visual(NeuHashtable *hashtable) {
    printf("[");
    for (int i = 0; i < hashtable->capacity; i++) {
        NeuNode* current = hashtable->table[i];
        int count = 0;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        printf("%d", count);
        if (i < hashtable->capacity - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}