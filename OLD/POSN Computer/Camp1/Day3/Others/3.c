#include <stdio.h>
int main(){
    int i,e,s,f;
    e=s=f=0;
    for(i=1;i<=100;i++){
        printf("%d ",i*3);
        if((i*3)%2==0){
           e++;s+=i*3;
        }
        if((i*3)%5==0)f+=i*3;
    }
    printf("\n%d %d %d",e,s,f);
}
