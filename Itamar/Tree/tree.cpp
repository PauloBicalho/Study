#include<iostream>

#include<stack>

using namespace std;

class node{
        public:
                int value;
                node *left, *right;

                node(int v,node *l=NULL, node *r=NULL): value(v),left(l),right(r){}
};

void print_tree( node &root, int mode ){
        stack<node *> s;
        stack<int> count;

        s.push( &(root) );
        count.push( 0 );

        while(s.size() > 0){
                if( count.top() == mode )
                        cout << s.top()->value << " ";

                switch( count.top() ){
                case 0:
                        count.top()++;
                        if( s.top()->left != NULL ){
                                s.push( s.top()->left );
                                count.push(0);
                        }
                        break;
                case 1:
                        count.top()++;
                        if( s.top()->right != NULL ){
                                s.push( s.top()->right );
                                count.push(0);
                        }
                        break;
                case 2:
                        s.pop();
                        count.pop();
                        break;

                }
        }
        cout << "\n";
}


int main(){
//                7
//              /   \ 
//            3      8
//          /   \
//        1       5
//       / \     / \ 
//      0   2   4   6


        node zero(0);
        node two(2);
        node one(1,&zero);

        node four(4);
        node six(6);
        node five(5,&four,&six);

        node three(3,&one,&five);
        node eight(8);

        node seven(7,&three,&eight);

        //pre-order
        cout << "Pre-order\n";
        print_tree(seven,0);

        //in-order
        cout << "\nIn-order\n";
        print_tree(seven,1);

        //pos-order
        cout << "\nPos-order\n";
        print_tree(seven,2);
}
