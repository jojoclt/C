#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
/*
1 2 3 4 5 6 7
9 8 7 6 5 4 3
2 4 6 8 5 3 9
*/
main(){
    int a[3][7],i,j,k,c[5];
    for(i=0;i<3;i++){
        for(j=0;j<7;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(k=0;k<5;k++){
        c[k]=0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                c[k]+=a[i][j+k];
            }
        }
        printf("%d ",c[k]);
    }
    return 0;
}

