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
        s.push(6);

        Node *n = s.pop();
        for(int i=0; i<3; i++){
                cout << n->value << "\n";
                delete(n);
                n = s.pop();
        }
        delete(n);

        return 0;
}
