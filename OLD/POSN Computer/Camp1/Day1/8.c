#include<stdio.h>
#include<conio.h>
main(){
    int i,sum;
    sum=100;
    /*������100������ٻ�Ш����� 99+100+=5050*/
    for (i=1;i<100;i++){
        printf("%d+", i);
        sum+=i;
    }
    printf("100=%d",sum);
    getch();
}
