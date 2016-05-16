#include<iostream>
#include<climits>

using namespace std;

int main(){
        unsigned int i = -1;
        unsigned int j = 4294967295;

        cout << i << " - " << (i==-1) << " " << INT_MAX << "\n";
        cout << i << " - " << (j==-1) << " " << INT_MAX << "\n";
        cout << i << " - " << (j==i) << " " << INT_MAX << "\n";

}


