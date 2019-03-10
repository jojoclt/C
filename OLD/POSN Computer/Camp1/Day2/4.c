#include<stdio.h>
#include<math.h>
main(){
    float g,h,bmi;
    printf("Enter weight in kilograms:");
    scanf("%f",&g);
    printf("Enter height in meters:");
    scanf("%f",&h);
    bmi=g/pow(h,2);
    printf("Your BMI is %f.\n",bmi);
    if (bmi<=18.5)printf("You are underweight.");
    else if (bmi<25)printf("You are in healthy condition.");
    else printf("lol you fat\nThat is, you are overweight.");
    getch();
}
