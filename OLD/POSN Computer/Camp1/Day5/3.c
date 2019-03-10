#include<stdio.h>
#include<stdlib.h>
main(){
    char x[1005];
    int i,j,k,n,max,a[1005];
    for (i=0;i<1005;i++){
        scanf("%s",&x);
        if (x[0]=='x')break;
        else a[i]=atoi(x);
    }
    for (j=0;j<i;j++){
        max = 1<<31-1;
        for(k=j;k<i;k++){
            if (a[k]<max){
                max=a[k];
                n=a[j];
                a[j]=a[k];
                a[k]=n;
            }
        }
    }
    for (j=0;j<i;j++)printf("%d ",a[j]);
    if (i%2!=0) printf("\nMedian = %d",(a[i/2]+a[i/2+1])/2);
    else {
        j=((float)i/2)+0.5;
        printf("\nMedian = %d",a[j]);
    }
}
