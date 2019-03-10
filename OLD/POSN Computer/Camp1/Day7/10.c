#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int i,n,d,b=0;
    printf("Days: ");scanf("%d",&n);
    while(1){
        printf("Day of the 1st (1=Sunday, 2=Monday and so on): ");
        scanf("%d",&d);
        if(d<1||d>7)printf("Invalid, try again\n");
        else break;
    }
    for(i=0;i<n;i++){
        d%=7;
        d++;
        if(i%2==0){
            if (d==4)b+=3;
            else if(d==6)b+=2;
        }
    }
    printf("%d",b);
}

