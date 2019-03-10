#include<stdio.h>
#include<math.h>

main(){
    int n,d,i,b=0;
    printf("Enter days in the month and day the 1st is (1=Monday, 2=Tuesday,...) :\n");
    scanf("%d %d",&n,&d);
    d--;
    for(i=1;i<=n;i++){
        if(d==2)b+=3;
        else if(d==4)b+=2;
        d++;
        d%=7;
    }
    printf("%d",b);
}
