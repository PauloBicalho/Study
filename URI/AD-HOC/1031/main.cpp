#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int last(int n, int k){
        n =  n-1;

        int r = 1;
        for(int i = 2; i<= n; i++){
                r = (r+k-1) % i + 1;

        }

        return r+1;
}

int main(){
        int n;

        scanf("%d",&n);
        while( n!=0){
                int i = 1;
                int r = last(n,i);
                while( r != 13 ){
                        r = last(n,++i);
                }
                printf("%d\n",i);


                //for( int i=1; i<=14; i++){
                //        int r = last(12,i);
                //        printf("%d: %d\n",i,r);
               // }
        
                scanf("%d",&n);
        }
}
