#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[8]={6,8,4,3,7,5,3,1};
main(){
    char x;
    int n,i;
    scanf("%c",&x);scanf("%d",&n);
    if(x=='L'){
        for(i=n;i<n+8;i++){
            printf("%d ",a[i%8]);
        }
    }
    else if(x=='R'){
        for(i=8-n;i<16-n;i++){
            printf("%d ",a[i%8]);
        }
    }
    else return 0;
    return 0;
}

