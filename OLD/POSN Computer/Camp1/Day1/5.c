#include<stdio.h>
#include<conio.h>
main(){
    int x,y,z;
    float sum,mean;
    printf("Enter 3 integers:");
    scanf("%d%d%d",&x, &y, &z);
    sum = x+y+z;
    mean = sum/3;
    printf("Mean = %f", mean);
    getch();
}
