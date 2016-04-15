#include<stdlib.h>
#include<stdio.h>
#include "binary_tree.h"


int main(){
        node_t* root = malloc( sizeof(node_t) );
        root->key.value = -10;

        key_type key1, key2, key3, key4, key5, key6;

        key1.value = 1;
        key2.value = 2;
        key3.value = 3;
        key4.value = 4;
        key5.value = 5;
        key6.value = 6;


        insert_key(root,key3);
        insert_key(root,key1);
        insert_key(root,key5);
        insert_key(root,key4);
        insert_key(root,key2);
        insert_key(root,key6);

        print_tree(root);
        printf("\n\n");

        node_t* node = search_key(root,key6);
        if( node != NULL )
        printf("%d\n\n",node->key.value);


        remove_key(root, key6);
        print_tree(root);
        printf("\n\n");

        return 0;
}
