#include<stdio.h>
#include<conio.h>
main(){
    int i,sum;
    sum=100;
    /*ถ้าให้100อยู่ในลูปจะจบด้วย 99+100+=5050*/
    for (i=1;i<100;i++){
        printf("%d+", i);
        sum+=i;
    }
    printf("100=%d",sum);
    getch();
}
