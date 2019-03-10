#include<stdio.h>
main(){
    int a[5],i,max,min,sum;
    float avg;
    max=1-1<<31;min=1<<31-1;sum=0;
    for (i=0;i<5;i++){
        scanf("%d",&a[i]);
        if (max<a[i])max=a[i];
        if (min>a[i])min=a[i];
        sum+=a[i];
    }
    avg=(float)sum/5;
    printf("Max = %d Min = %d Sum = %d Avg = %f",max,min,sum,avg);
}
