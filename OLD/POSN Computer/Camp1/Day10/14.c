#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
/*
1 2 3 4 5
9 8 7 6 20
4 3 2 14 6
15 5 3 9 20
7 16 1 31 4
*/
main(){
    int r,i,j,t;
    while(1){
        scanf("%d",&r);
        if((r<3||r>23)||(r%2==0))printf("Error\n");
        else break;
    }
    int a[r][r];
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<r/2;j++){
            if(i>j-1&&i<r-j){
                t=a[i][j];
                a[i][j]=a[i][r-j-1];
                a[i][r-j-1]=t;
            }
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

