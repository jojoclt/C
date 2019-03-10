#include<stdio.h>
#include<math.h>

main(){
    int i, a[1005],n,max;
    printf("Amount of integers: ");scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max=1-1<<31;
    for (i=0;i<n;i++){
        if (a[i]>max)max=a[i];
    }
    printf("Max = %d",max);
}
