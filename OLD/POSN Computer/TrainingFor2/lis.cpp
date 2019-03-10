#include<bits/stdc++.h>
using namespace std;
int a[200000],n,mem[200000];
void f(int x){
    int t=0;
    int max=0;
    for(int i=x;i<n;i++){
        if(a[i]>a[x])t=mem[i]+1;
        if(t>max)max=t;
    }
    mem[x]=max;
    //printf("mem[%d]=%d\n",x,max);
    if(x>0)f(x-1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    f(n-1);
    int max=0;
    for(int i=0;i<n;i++){
        if(mem[i]>max)max=mem[i];
    }
    printf("%d",max+1);
    return 0;
}
/*
7
4 1 5 6 2 3 7
*/
