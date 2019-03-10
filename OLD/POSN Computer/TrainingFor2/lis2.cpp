#include<bits/stdc++.h>
using namespace std;
int a[200000],n,mem[200000];
void f(int x){
    int t=0;
    for(int i=x;i<n;i++){
        if(a[i]>a[x]&&mem[i]+1>t)t=mem[i]+1;
    }
    mem[x]=t;
    if(x>0)f(x-1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    f(n-1);
    int max=0;
    //for(int i=0;i<n;i++)printf("before:mem[%d]=%d\n",i,mem[i]);
    sort(&mem[0],&mem[n]);
    //for(int i=0;i<n;i++)printf("after:mem[%d]=%d\n",i,mem[i]);
    printf("%d",mem[n-1]+1);
    return 0;
}
/*
7
4 1 5 6 2 3 7
*/
