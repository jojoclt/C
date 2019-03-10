#include<stdio.h>
#include<math.h>
int rev(int x){
    return x;
}
main(){
    int n,i,x,y;
    scanf("%d",&n);
    y=0;
    for(i=0;;i++){
        x=n;
        x-=pow(10,i);
        if (x<0)break;
    }
    for(x=0;x<i;x++){
        y=rev((int)(n/pow(10,x))%10);
        printf("%d",y);
    }
}
