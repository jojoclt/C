#include<stdio.h>
main(){
    int x,n,p,i;
    scanf("%d",&x);
    p=0;
    for (n=2;n<=x;n++){
        for(i=2;i<n;i++){
            if(n%i == 0) break;
            else if (i==n-1) p++;
            else continue;
        }
    }
    printf("The number of prime numbers that are not greater than x is %d.\n",p+1);
    /* +1 because 2 is impossible to define as prime by the above definition*/

    getch();

}
