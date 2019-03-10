#include<stdio.h>
int count_factor(int a[10]){
    int i,j=0;
    for (i=0;i<10;i++){
        if (a[i]==1||
            a[i]==2||
            a[i]==4||
            a[i]==5||
            a[i]==8||
            a[i]==10||
            a[i]==20||
            a[i]==40||
            a[i]==-1||
            a[i]==-2||
            a[i]==-4||
            a[i]==-8||
            a[i]==-5||
            a[i]==-10||
            a[i]==-20||
            a[i]==-40)j++;
    }
    return j;
}
main(){
    int a[10],i;
    for (i=0;i<10;i++)
        scanf("%d",&a[i]);
    printf("There are %d factors of 40",count_factor(a));
}
