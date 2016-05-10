#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<limits.h>

using namespace std;

int getRow(char num){
        int row;
        switch(num){
        case 'u': row = 0; break;
        case 'd': row = 1; break;
        case 't': row = 2; break;
        }
        return row;
}

int getCol(char type){
        int col;
        switch(type){
        case 'c': col = 0; break;
        case 't': col = 1; break;
        case 'q': col = 2; break;
        }
        return col;
}

int solve(int **matrix){
        int sumR = 0, sumC = 0, sumD1 = 0, sumD2 = 0;
      
        int uniq = 0;
        for(int i=0; i<3; i++)
                for(int j=0; j<3; j++){
                        uniq += matrix[i][j] / 3;
                        matrix[i][j] %= 3;
                }
        for(int i=0; i<3; i++){
                int minR = INT_MAX;

                for(int j=0; j<3; j++){
                        if( matrix[i][j] < minR )  minR = matrix[i][j];
                }
                if( minR != 0 ){
                        for(int j=0; j<3; j++)
                                matrix[i][j] -= minR;

                }
                sumR+= minR;
        }

        for(int i=0; i<3; i++){
                int minC = INT_MAX;
                for (int j=0; j<3; j++){
                        if( matrix[j][i] < minC )  minC = matrix[j][i];
                }
                if( minC != 0 ){
                        for (int j=0; j<3; j++)
                                matrix[j][i] -= minC;

                }
                sumC += minC;
        }
        int sumD=0;
        for(int i=0; i<3; i++){
                int f = matrix[i][0];
                for(int j=0; j<3; j++){
                        if( j == i )
                                continue;

                        int s = matrix[j][1];
                        int k = 3 - (i+j);
                        
                        int t = matrix[k][2];

                        int r = f < s ? f < t ? f:t : s < t? s: t;
                        sumD += r;

                        if( sumD != 0){
                                matrix[i][0] -= r;
                                matrix[j][1] -= r;
                                matrix[k][2] -= r;
                        }

                }
        }

        int max=sumR+sumC+sumD;

        if( uniq + max == 2111231231 ){
                printf("Uniq: %d\tSumR: %d\tSumC: %d\tSumD: %d\n",uniq,sumR,sumC,sumD);
                for( int i=0; i<3; i++){
                        for(int j=0; j<3; j++)
                                printf("%d ",matrix[i][j]);
                        printf("\n");
                }

        }


        return uniq+max;
}

int main(){
        int n;
        scanf("%d\n",&n);

        while( n != 0 ){
                int **matrix;

                matrix = (int **) malloc(9*sizeof(int *));
                for( int i=0; i<3; i++)
                        matrix[i] = (int *) calloc(3,sizeof(int));

                for( int i=0; i<n; i++){
                        char num, type;
                        scanf("%c%*s %c%*s\n",&num,&type);
                        
                        int col = getRow(num);
                        int row = getCol(type);
                        matrix[row][col]++;

                }

                int r = solve(matrix);
                printf("%d\n",r);

                scanf("%d\n",&n);
        }

        return 0;
}
