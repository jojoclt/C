#include<stdio.h>
#include<math.h>
/*
5 11
D L L D D D R R U R R
*/
main(){
    int n,m,i,j;
    while(1){
        scanf("%d",&n);
        if(n<1||n>15)printf("Error\n");
        else break;
    }
    while(1){
        scanf("%d",&m);
        if(m<1||m>150)printf("Error\n");
        else break;
    }
    char c[n],d[n][n];
    int a,b;
    a=0;b=(n-1)/2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            d[i][j]=' ';
    }
    d[a][b]='S';
    for(i=0;i<m;i++){
        scanf(" %c",&c[i]);
    }
    for(i=0;i<m;i++){
        if(c[i]=='D'){
            a++;
            d[a][b]='*';
        }
        else if(c[i]=='U'){
            a--;
            d[a][b]='*';
        }
        else if(c[i]=='L'){
            b--;
            d[a][b]='*';
        }
        else if(c[i]=='R'){
            b++;
            d[a][b]='*';
        }
        else return 0;
    }
    d[a][b]='L';
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c",d[i][j]);
        }
        printf("\n");
    }
}
