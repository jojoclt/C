#include<stdio.h>
main(){
    int A[10],i,j,max,n;
    for(i=0;i<10;i++)scanf("%d",&A[i]);
    for(i=0;i<10;i++){
        max=1<<31-1;
        for(j=i;j<10;j++){
            if(A[j]<max){
                max=A[j];
                n=A[i];
                A[i]=A[j];
                A[j]=n;
            }
        }
        printf("%d ",A[i]);
    }



}
