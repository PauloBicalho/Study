#include<iostream>

using namespace std;

typedef int data_t;

class Node{
        public:
                data_t value;
                Node * next;

                Node(data_t value): value(value), next(NULL){ }
};

class Stack{
        public:
                Node *top;
                int size;

                Stack(): top(NULL), size(0){}
                ~Stack(){ while( this->top != NULL )  delete(this->pop()); }

                void push(data_t value){
                        Node *node = new Node(value);
                        node->next = this->top;
                        this->top = node;
                        this->size++;
                }

                Node *pop(){
                        if( this->top == NULL )
                                return NULL;

                        Node *node = this->top;
                        this->top = this->top->next;
                        this->size--;
                        return node;
                }

};
