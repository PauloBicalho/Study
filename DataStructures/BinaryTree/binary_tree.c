#include"binary_tree.h"
#include<stdlib.h>
#include<stdio.h>

key_type* make_key(int value){
        key_type* key = malloc( sizeof(key_type) );
        key->value = value;

        return key;
}


int comp_key(key_type key1, key_type key2){
        if (key1.value < key2.value)
                return -1;
        else if( key1.value > key2.value )
                return 1;
        else
                return 0;

}

void copy_key( key_type * key1, key_type key2 ){
        key1->value = key2.value;
}

node_t* search_key( node_t* node, key_type key ){
        if( node == NULL ){
                printf("Node not found\n");
                return NULL;
        }

        if( comp_key( key, node->key ) == 0 )
                return node;
        
        if( comp_key( key, node->key ) == -1 )
                search_key( node->left, key );
        else
                search_key( node->right, key);
}

void insert_key( node_t* node, key_type key ){
        node_t** child;

        if( comp_key( key, node->key ) == 0 ){
                printf("Node already exist!\n");
                return;
        }
        
        if( comp_key( key, node->key ) == -1 )
                child = &(node->left);
        else
                child = &(node->right);
        
        if( *child != NULL )
                insert_key( *child, key );
        else{
                *child = malloc(sizeof(node_t));
                copy_key( &( (*child)->key ), key);
                (*child)->left = NULL;
                (*child)->right = NULL;
                (*child)->parent = node;
                return;
        }
}

node_t* find_successor(node_t* node){
        while( node->left != NULL ){
                node = node->left;
        }
        return node;
}

node_t* find_predecessor(node_t* node){
        while( node->right != NULL ){
                node = node->right;
        }
        return node;
}

void free_node(node_t* node){
        if( comp_key( node->key, node->parent->key ) == 1 )
                node->parent->right = NULL;
        else
                node->parent->left = NULL;

        free(node);
}

node_t* remove_key( node_t* root, key_type key ){
        node_t* node = search_key(root,key);

        if( node == NULL ){
                printf("Node not found!\n");
                return;
        }

        if( node->right == NULL && node->left == NULL ){
                printf("node:%d\n", node->key.value);
                free_node(node);
                return;
        }

        node_t* replace = NULL;
        if( node->left != NULL ){
                replace = find_predecessor(node->left);
                copy_key( &(node->key), replace->key);
        } else if( node->right != NULL ){
                replace = find_successor(node->right);
                copy_key( &(node->key), replace->key);
        } 
        
        free_node(replace);
}


void print_tree( node_t* node){
        if( node == NULL ){
                printf("N ");
                return;
        }

        printf("( ");
        print_tree( node->left );
        printf("- ");
        printf("%d ",node->key.value);
        printf("- ");
        print_tree( node->right );
        printf(") ");
}
