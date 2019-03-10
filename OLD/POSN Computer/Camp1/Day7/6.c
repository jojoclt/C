#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int n,x,i,j,k=0;
    char c='A'-1;
    while(1){
        printf("N=");scanf("%d",&n);
        if(n<2||n>20)printf("Invalid, try again.\n");
        else break;
    }
    while(1){
        printf("X=");scanf("%d",&x);
        if(x<2||x>n)printf("Invalid, try again.\n");
        else break;
    }
    char a[x];
    for(i=0;i<n;i++){
        c+=i+1;
        for(j=0;j<n;j++){
            if(i>=x-1&&j==x-1){
                a[k++]=c;
                printf("%c ",c--);
            }
            else if(j>=n-i-1)
                printf("%c ",c--);
            else printf("  ");
        }
        c+=i+1;
        printf("\n");
    }
    for(i=0;i<x;i++)
        printf("%c ",a[i]);
}

