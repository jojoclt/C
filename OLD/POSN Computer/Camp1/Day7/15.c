#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    char c='A';
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("%c",c++);
            if(c>'Z')c-=26;
        }
        printf("\n");
    }
    if(i<4)printf("_");
    else{
            c='E';
        for(i=2;i<n-1;i++){
            for(j=0;j<i-1;j++){
                printf("%c",c++);
                if(c>'Z')c-=26;
            }
            c+=2;
            if(c>'Z')c-=26;
            printf("\n");
        }
    }
}

