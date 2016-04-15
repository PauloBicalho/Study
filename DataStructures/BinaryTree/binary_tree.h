#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct key_type{
        int value;
} key_type;

typedef struct node_t node_t;

struct node_t{
        key_type key;
        
        node_t* parent;
        node_t* left;
        node_t* right;
};

key_type* make_key(int value);
int comp_key(key_type key1,key_type key2);
void copy_key( key_type* key1, key_type key2);


node_t* search_key( node_t* node, key_type key );
node_t* remove_key( node_t* root, key_type key);

void insert_key( node_t* node, key_type key );
void free_node(node_t* node);

void print_tree( node_t* node);

#endif
