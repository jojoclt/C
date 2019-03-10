#include<stdio.h>
#include<math.h>

main(){
    int i,n,tmp;
    scanf("%d",&n);
    tmp=n;
    for(i=2;i<n;i++){
        tmp=n%i;
        if (tmp==0){
            printf("Not prime");break;
        }
    }
    if (n==1)printf("Not prime");
    else if (tmp!=0)printf("Prime");
}
