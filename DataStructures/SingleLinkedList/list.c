#include "list.h"

void init_list(list_t* list){
        list->head = malloc(sizeof(element_t));
        list->head->next = NULL;
        list->tail = list->head;
        list->size = 0;
}

void push_front(list_t *list, data_t data){
        element_t *element = malloc( sizeof(element_t) );
        element->next = list->head->next;
        element->data = data;

        if( list->size == 0 )
                list->tail = element;
        list->head->next = element;
        list->size++;
}

data_t pop_front(list_t *list){
        if( list->size == 0 )
                return -1;
        
        element_t *element = list->head->next;
        
        list->head->next = element->next;
        list->size--;

        if( list->tail == element )
                list->tail = list->head;

        data_t data = element->data;
        free(element);

        return data;
}

void push_back(list_t *list, data_t data){
        element_t *element = malloc( sizeof(element_t) );
        element->data = data;
        element->next = NULL;

        list->tail->next = element;
        list->tail = element;

        list->size++;
}

data_t pop_back(list_t *list){
        if( list->size == 0 )
                return -1;

        element_t *it;
        for( it = list->head; it->next->next != NULL; it = it->next );
        
        data_t data = it->next->data;
        free(it->next);
        it->next = NULL;

        list->size--;
        return data;
}

