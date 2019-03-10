#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int n,w,h,i,j,k=0;
    scanf("%d%d%d",&n,&w,&h);
    for (i=0;i<h;i++){
        for(j=0;j<w;j++){
            k%=n;
            printf("%c",'A'+k);
            k++;
        }
        k--;
        printf("\n");
    }
}

