#include<stdlib.h>
#include<stdio.h>

#include"list.h"

int main(int argc,char *argv[]){
        list_t list;

        init_list(&list);

        push_front(&list,1);
        push_front(&list,2);
        push_front(&list,3);
        push_front(&list,4);
        push_front(&list,5);

        printf("Pop\n");
        while( list.size != 0 ){
                printf("%d\n",pop_front(&list));
        }

        push_back(&list,1);
        push_back(&list,2);
        push_back(&list,3);
        push_back(&list,4);
        push_back(&list,5);

        printf("Pop\n");
        while( list.size != 0 ){
                printf("%d\n",pop_back(&list));
        }


        return 0;
}
