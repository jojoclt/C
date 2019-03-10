#include<stdio.h>
#include<conio.h>
main(){
    int x,y;
    float area;
    printf("Enter width:");
    scanf("%d", &x);
    printf("Enter height");
    scanf("%d", &y);
    area = x*y;
    printf("Area = %f", area);
    getch();
}
