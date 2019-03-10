#include<stdio.h>
#include<math.h>
main(){
    int x,y;
    printf("Enter an integer:");
    scanf("%d",&x);
    y=x%10;
    printf("The last digit is: ");
    if (y==0)printf("Zero");
    if (y==1)printf("One");
    if (y==2)printf("Two");
    if (y==3)printf("Three");
    if (y==4)printf("Four");
    if (y==5)printf("Five");
    if (y==6)printf("Six");
    if (y==7)printf("Seven");
    if (y==8)printf("Eight");
    if (y==9)printf("Nine");
}
