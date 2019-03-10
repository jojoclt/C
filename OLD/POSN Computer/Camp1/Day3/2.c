#include<stdio.h>
main(){
    int x,i,j;
    char b[1005];
    scanf("%d",&x);
    j=x;
    for(i=0;;i++){
        j-=(1<<i);
        if (j>0)continue;
        else break;
    }
    for(j=i;j>=0;j--){
        x-=(1<<j);
        if (x>=0) printf("1");
        else{
            x+=(1<<j);
            printf("0");
        }
    }
}
