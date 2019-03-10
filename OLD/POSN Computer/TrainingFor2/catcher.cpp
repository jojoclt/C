#include<bits/stdc++.h>
using namespace std;
int a[1005],n,mem[1005];
void f(int x){
    int t=0;
    int max=0;
    for(int i=x+1;i<n;i++){
        if(a[i]<=a[x])t=mem[i]+1;
        if(t>max)max=t;
    }
    mem[x]=max;
    //printf("mem[%d]=%d\n",x,max);
    if(x>0)f(x-1);
}
int main(){
    //scanf("%d",&n);
    int _a,cnt;
    while(scanf("%d",&_a))
    {
        if(_a==-1)return 0;
        cnt = 0;
        a[cnt++] = _a;
        while(scanf("%d",&_a))
        {
            if(_a==-1)break;
            a[cnt++] = _a;
        }
        n = cnt;
        f(n-1);
            int max=0;
            for(int i=0;i<n;i++){
                if(mem[i]>max)max=mem[i];
            }
            printf("ans=%d\n",max+1);

    }
    //for(int i=0;i<n;i++)scanf("%d",&a[i]);

    return 0;
}
/*
7
4 1 5 6 2 3 7
*/
