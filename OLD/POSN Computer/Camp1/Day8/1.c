#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>
int a[10],i,sum=0,*p;
main(){
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
        p=&a[i];
        sum+=*p;
    }
    printf("%d",sum);
}

