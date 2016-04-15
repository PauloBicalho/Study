#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[]){
        FILE* f = fopen(argv[1],"r");

        unsigned short int vector[27001];
        
        int i = 0;
        for(i=0; i<27001; i++)
                vector[i] = 0;

        int value = 0;
        while( fscanf(f,"%d\n", &value) != EOF ){
                vector[value] = 1;
        };

        for(i=0; i<27001; i++){
                if( vector[value] == 1 ){
                        printf("%d\n",i);
                }
                
        }

//        printf("%lu %llu\n",sizeof(long long int)*8, 1llu<<63);

        fclose(f);

        return 0;
}
