#include<stdio.h>
#include<conio.h>
main(){
    int i,N,x;
    float sum,mean;
    sum=0;
    printf("Enter amount of numbers:");
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        printf("Enter #%d:\n", i);
        scanf("%d", &x);
        sum=sum+x;
    }
    mean=sum/N;
    printf("Mean = %f", mean);
    getch();
}
