#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    char a[5],b[5];
    int i,j,x,y;
    for(i=0;i<5;i++){
        scanf(" %c",&a[i]);
    }
    for(i=0;i<5;i++){
        scanf(" %c",&b[i]);
    }
    for(y=0;y<5;y++){
        for(x=0;x<5;x++){
            if (a[x]==b[y])
                break;
        }
        if (x!=5)break;
    }

    if(x!=5&&y!=5){
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                if (i!=y){
                    if(j==x)printf("%c ",b[i]);
                    else printf("  ");
                }
                else printf("%c ",a[j]);
            }
            printf("\n");
        }
    }
    else {
        for(i=0;i<5;i++){
            for(j=0;j<6;j++){
                if (i==0){
                    if(j!=5)printf("%c ",a[j]);
                    else printf("%c ",b[0]);
                }
                else {
                    if (j!=5)printf("  ");
                    else printf("%c ",b[i]);
                }
            }
            printf("\n");
        }
    }
}

