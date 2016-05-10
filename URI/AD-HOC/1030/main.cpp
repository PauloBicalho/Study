#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main(){
        int NC, n, k;

        scanf("%d",&NC);

        for(int c=1; c<=NC; c++){
                scanf("%d %d", &n, &k);

                int r = 1;
                for(int i = 2; i<= n; i++){
                        r = (r+k-1) % i + 1;

                }
                printf("Case %d: %d\n",c,r);

        }
}
