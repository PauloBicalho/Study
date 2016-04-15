#include<iostream>
#include"myStack.h"

using namespace std;

int main(){
        Stack s = Stack();

        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        s.search();

        Node *n = s.pop();
        while( n != NULL ){
                cout << n->value << "\n";
                n = s.pop();
        }

        return 0;
}
