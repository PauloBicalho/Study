#include<iostream>
#include"myQueue.h"

using namespace std;


int main(){
        Queue q = Queue();

        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        q.enqueue(6);

        Node *n = q.dequeue();
        for(; n != NULL;){
                cout << n->value << "\n";
                delete(n);
                n = q.dequeue();
        }
        delete(n);

        return 0;
}
