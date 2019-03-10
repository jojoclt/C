#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    int n,i,j;
    while(1){
        printf("Input index : ");scanf("%d",&n);
        if(n<0||n>9)printf("Error\n");
        else break;
    }
    int a[n];
    for(i=0;i<n;i++){
        while(1){
            printf("Input index [%d]: ",i);scanf("%d",&a[i]);
            if(n<0||n>9)printf("Error\n");
            else break;
        }
    }
    for(i=0;i<n;i++)
        printf(" %d",a[i]);
    printf("\n");
    printf("  ");
    for(i=0;i<n;i++)
        printf(" _");
    printf("\n");
    for(i=10;i>0;i--){
        for(j=0;j<2*n+2;j++){
            if(j==0){
                printf("%2d",i);
            }
            else if(j%2!=0){
                printf("|");
            }
            else {
                if(a[j/2-1]>=i)printf("*");
                else printf(" ");
            }
        }
        printf("\n");
    }
    printf("  ");
    for(i=0;i<n;i++)
        printf(" _");
    printf("\n");
    printf("  ");
    for(i=0;i<n;i++)
        printf(" %d",i);
}

