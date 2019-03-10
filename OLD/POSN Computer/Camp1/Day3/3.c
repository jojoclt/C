
#include<stdio.h>
int main(){
    int n,i,x,min,max,sum;
    min=100;max=sum=0;
    printf("The amount of numbers you will input after this: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x<min)min=x;
        if(x>max)max=x;
        sum+=x;
    }
   float  avg=sum/n;
    printf("Min=%d Max=%d Sum=%d Avg=%f",min,max,sum,avg);
    return 0;
}
