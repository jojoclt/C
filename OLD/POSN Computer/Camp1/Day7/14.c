#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>
#include<time.h>
main(){
    int i,r,t=0;
    srand(time(NULL));
    for(i=0;i<50;i++){
        r=(rand()%80)+20;
        printf("%d ",r);
        if(r%3==0)t++;
    }
    printf("\n%d",t);
}

