#include<stdio.h>
main(){
    int x,i,a,b,c;
    a=b=0;
    for (i=0;i<5;i++){
        scanf("%d",&x);
        if(x%2==0)a++;
        else b++;
    }
    printf("Odd=%d\nEven=%d\n",b,a);
    getch();
}
