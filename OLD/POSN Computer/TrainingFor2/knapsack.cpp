#include<bits/stdc++.h>
using namespace std;
int n,m,tv,tw,ans;
int v[1005],w[1005];
void f(int x){
    //printf("hello x = %d\n",x);
    tv+=v[x];
    tw+=w[x];
    if(tw<=m&&tv>ans){ans=tv;/*printf("%d ans=%d weight = %d\n",x,ans,tw);*/}
    for(int i=x+1;i<n;i++){
        f(i);
    }
    tv-=v[x];
    tw-=w[x];
}
main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    for(int i=0;i<n;i++)scanf("%d",&w[i]);
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        tv=tw=0;
        f(i);
    }
    printf("%d",ans);
}
/*
3
60 100 120
10 20 30
50
*/
