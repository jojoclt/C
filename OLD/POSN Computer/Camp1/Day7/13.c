#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int a[5],b[5],i,j;
    for(i=0;i<5;i++){
        scanf("%d",&a[i]);
        j=(i+3)%5;
        b[j]=a[i];
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(j==2)
                printf("%d ",b[i]);
            else if (i==2)
                printf("%d ",b[j]);
            else printf("  ");
        }
        printf("\n");
    }
}

