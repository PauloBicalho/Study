#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[]){
        FILE* f = fopen(argv[1],"r");


        unsigned long long int vector[422];

        int i = 0;
        for(i=0; i<422; i++)
                vector[i] = 0;

        int value = 0;
        while( fscanf(f,"%d\n", &value) != EOF ){
                int index = value >> 6;
                int bit = value ^ (64 << index);

                vector[index] |= (1llu << bit );
                
        };

        for(i=0; i<27001; i++){
                int index = i/64;
                int bit = i % 64;

                if( vector[index] & (1llu << bit ) ){
                        printf("%d\n",i);
                }
                
        }

//        printf("%lu %llu\n",sizeof(long long int)*8, 1llu<<63);

        fclose(f);

        return 0;
}
