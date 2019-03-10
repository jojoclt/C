#include<bits/stdc++.h>
using namespace std;
int n,m,tv,tw,ans;
int v[1005],w[1005],mem[1005][1005];
int f(int x, int y){
    if(y<0)return -1e9;
    if(x==n)return 0;
    if(!mem[x][y]){
        mem[x][y]=max(mem[x][y],f(x+1,y));
        mem[x][y]=max(mem[x][y],v[x]+f(x+1,y-w[x]));
    }
    return mem[x][y];
}
main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    for(int i=0;i<n;i++)scanf("%d",&w[i]);
    scanf("%d",&m);
    printf("%d",f(0,m));
}
/*
3
60 100 120
10 20 30
50
*/
