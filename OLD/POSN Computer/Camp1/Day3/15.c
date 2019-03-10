#include<stdio.h>
main(){
    int A[20],i,j,b[20],n;
    for(i=0;i<20;i++){
        b[i]=0;
    }
    printf("The number of integers you want in your array (<20): ");
    scanf("%d",&n);
    if (n<0||n>20)printf("Error");
    else {
        for(i=0;i<n;i++){
            scanf("%d",&A[i]);
            for(j=0;j<i;j++){
                if(A[i]==A[j]){b[j]++;break;}
                else continue;
            }
        }
        for(i=0;i<20;i++){
            if (b[i]>0)printf("%d %d\n",A[i],b[i]+1);
        }
    }
    return 0;
}
