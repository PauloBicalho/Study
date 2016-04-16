#include <iostream>

using namespace std;

typedef int data_t;

class Node{
        public:
                data_t value;
                Node *next;

                Node(data_t value): value(value), next(NULL){}
};

class Queue{
        public:
                Node *first, *last;
                int size;

                Queue(): first(NULL), last(NULL), size(0){}
                ~Queue(){ while( first != NULL ) delete(dequeue()); }

                void enqueue(data_t value){
                        Node *n = new Node(value);

                        if( first == NULL )
                                first = last = n;
                        else{
                                last->next = n;
                                last = n;
                        }
                        size++;
                }

                Node * dequeue(){
                        if( first == NULL )
                                return NULL;
                        
                        Node *n = first;
                        first = first->next;
                        size--;

                        return n;
                }
};
