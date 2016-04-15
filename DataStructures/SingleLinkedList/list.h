#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

typedef int data_t;

typedef struct element element_t;

struct element{
        data_t data;
        element_t *next;
};

typedef struct{
        element_t *head, *tail;
        int size;
} list_t;

void init_list(list_t *list);
void push_front(list_t *list, data_t data);

data_t pop_front(list_t * list);

#endif
