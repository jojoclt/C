#include<stdio.h>
#include<math.h>
main(){
    float x1,y1,x2,y2,l;
    printf("Enter x1:");
    scanf("%f",&x1);
    printf("Enter y1:");
    scanf("%f",&y1);
    printf("Enter x2:");
    scanf("%f",&x2);
    printf("Enter y2:");
    scanf("%f",&y2);
    l=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    printf("The length between the two points is %f.\n",l);
    getch();
}
