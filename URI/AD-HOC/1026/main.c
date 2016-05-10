#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[]){

        unsigned long int a,b,c;
        while ( scanf("%lu %lu", &a, &b) != EOF ){
                c = a^b;
                printf("%lu\n", c);
        }

}
