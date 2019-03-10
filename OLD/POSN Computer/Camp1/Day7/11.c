#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    char a[1005];
    int w,h,i,j,k=0;
    scanf(" %s%d%d",&a,&w,&h);
    for (i=0;i<h;i++){
        for(j=0;j<w;j++){
            k%=strlen(a);
            printf("%c",a[k]);
            k++;
        }
        k--;
        printf("\n");
    }
}

