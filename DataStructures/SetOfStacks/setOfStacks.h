#include<iostream>
#include<vector>

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


class SetOfStacks{
        public:
                vector< Stack > stacks;
                int curr_stack, capacity;

                SetOfStacks(int capacity): capacity(capacity), num_stacks(0),
                                           stacks( vector< Stack > (1,Stack()) ) {}

                void push(data_t value){
                        if( stacks[curr_stack].size == capacity ){
                                stacks.push_back(Stack());
                                curr_stack++;
                        }
                        stack[curr_stack].push(value);
                }

                Node *pop(){
                        Node *n = stacks[curr_stack].pop();

                        if( curr_stack != 0 and stacks[curr_stack].size == 0 ){
                                stacks.pop_back();
                                curr_stack--;
                        }
                        return n;
                }
                


}
