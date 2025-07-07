#ifndef NEU_HASHTABLE_H
#define NEU_HASHTABLE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCALE_FACTOR 2
#define LOAD_FACTOR 0.7
#define INITIAL_CAPACITY 8

typedef struct {
    char itemID[255];
    char itemName[255];
    double itemPrice;
    int itemQuantity;
} Item;

typedef struct NeuNode {
    Item data;
    struct NeuNode* next;
} NeuNode;

typedef struct {
    NeuNode** table;
    size_t size;
    size_t capacity;
} NeuHashtable;


NeuHashtable* create_hashtable(int capacity);
void free_hashtable(NeuHashtable* hashtable);
void add_item(NeuHashtable* hashtable, const char* itemID, const char* itemName, double itemPrice, int itemQuantity);
Item* get_item(NeuHashtable* hashtable, const char* itemID);
void remove_item(NeuHashtable* hashtable, const char* itemID);
void print_hashtable(NeuHashtable* hashtable);
void print_table_visual(NeuHashtable* hashtable);
double get_load_factor(NeuHashtable* hashtable);



#endif /* NEU_HASHTABLE_H */
