#include<iostream>

using namespace std;

typedef int data_t;

class Node{
        public:
                data_t value;
                Node * next;

                Node(data_t value){ this->value = value; this->next = NULL; }
};

class Stack{
        public:
                Node *top;
                int size;

                Stack(){ this->top == NULL; size=0; }

                void push(data_t value){
                        Node *node = new Node(value);

                        if( node->next == NULL )
                                cout << "1Value: " << node->value << " Next: NULL\n";

                        if( this->top == NULL )
                                node->next = NULL;
                        else
                                node->next = this->top;
                       
                        if( node->next != NULL )
                                cout << "2Value: " << node->value << " Next: " << node->next->value << "\n";
                        if( node->next == NULL )
                                cout << "2Value: " << node->value << " Next: NULL\n";
                        
                        cout << "\n";
                        
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

                void search(){
                        Node *node = this->top;

                        while(node != NULL){
                                cout << "value: " << node->value << "\n";
                                node = node->next;
                        }
        
                }

};
