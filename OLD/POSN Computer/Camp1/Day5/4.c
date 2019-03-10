#include<stdio.h>
main(){
    char a[13],b[17];
    int i;
    for (i=0;i<13;i++)scanf(" %c",&a[i]);
    b[0]=a[0];
    b[1]='-';
    for (i=2;i<=5;i++)b[i]=a[i-1];
    b[6]='-';
    for (i=7;i<=11;i++)b[i]=a[i-2];
    b[12]='-';
    b[13]=a[10];
    b[14]=a[11];
    b[15]='-';
    b[16]=a[12];
    for (i=0;i<17;i++)printf("%c",b[i]);
}
