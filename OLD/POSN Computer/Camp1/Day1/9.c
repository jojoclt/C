#include<stdio.h>
#include<conio.h>
main(){
    int i, prd;
    prd = 10;
    /*������10������ٻ�Ш�����9x10x=3628800*/
    for(i=1;i<10;i++){
        printf("%dx",i);
        prd*=i;
    }
    printf("10=%d",prd);
    getch();
}
