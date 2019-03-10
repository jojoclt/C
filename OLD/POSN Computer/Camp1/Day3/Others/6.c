#include<stdio.h>
main(){
    char a[1005];
    int i,j,n1,n2,n3,n4;
    for(i=0;i<1005;i++)a[i]=255;
    n1=n2=n3=n4=i=0;
    while(1){
        scanf("%c",&a[i]);
        if (a[i]==10){
            a[i]=255;break;
        }
        else i++;
    }
    for(j=0;j<i;j++){
        if (a[j]>=65&&a[j]<=90)n1++;
        else if (a[j]>=97&&a[j]<=122)n2++;
        else if (a[j]>=48&&a[j]<=57)n3++;
        else n4++;
    }
    printf("A-Z: %d\na-z: %d\n0-9=%d\nother=%d",n1,n2,n3,n4);
}
