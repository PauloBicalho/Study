#include<stdlib.h>
#include<stdio.h>


int search(int *vector, int start, int end, int value){
        if( start > end  )
                return 0;

        int m = ( (unsigned long)start + (unsigned long)end) >> 1;

        if( value == vector[m] )
                return 1;

        if( value < vector[m] )
                return search(vector,start,m-1,value);
        else
                return search(vector,m+1,end,value);

}

int search2(int *vector, int start, int end, int value){
        while( start <= end ){
                int m = ( (unsigned long)start + (unsigned long)end) >> 1;

                if( value == vector[m] )
                        return 1;

                if( value < vector[m] )
                        end = m-1;
                else
                        start = m+1;
        }
        return 0;

}

int main(int argc,char *argv[]){

        int value = atoi(argv[1]);
        int *vector = (int *) malloc(10*sizeof(int));

        vector[0] = 1; vector[1] = 3; vector[2] = 7;
        vector[3] = 9; vector[4] = 11; vector[5] = 13;
        vector[6] = 15; vector[7] = 21; vector[8] = 27;
        vector[9] = 29;

        printf("%d - ", search(vector, 0,9, value));
        printf("%d\n", search2(vector, 0,9, value));
        


}
