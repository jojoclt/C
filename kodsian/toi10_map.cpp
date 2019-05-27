#include <bits/stdc++.h>
using namespace std;
struct node{
    int val,x,y;
}t;
int m,n;
int N,x=1e9,y=1e9;
int t1,t2,t3,i,j;
bool visit[405][405];
int a[405][405];
int l[40001],r[40001],u[40001],d[40001];
queue <node> q;
int main(){
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    memset(u,-1,sizeof(u));
    memset(d,-1,sizeof(d));
    scanf("%d%d",&m,&n);
    N = m*n-1;
    for (i = 0; i < N; i++){
        scanf("%d %c%d",&t1,&t2,&t3);
        if (t2 == 'U') {
            d[t1] = t3;
            u[t3] = t1;
        }
        else{
            r[t1] = t3;
            l[t3] = t1;
        }
    }
    q.push({t1,201,201});
    while (!q.empty()){
        t = q.front(); q.pop();
        if (visit[t.x][t.y]) continue;
        x = min(x,t.x), y = min(y,t.y);
        a[t.x][t.y] = t.val;
        visit[t.x][t.y] = true;
        if (d[t.val] != -1) q.push({d[t.val],t.x+1,t.y});
        if (u[t.val] != -1) q.push({u[t.val],t.x-1,t.y});
        if (r[t.val] != -1) q.push({r[t.val],t.x,t.y+1});
        if (l[t.val] != -1) q.push({l[t.val],t.x,t.y-1});
    }
    for (i = x; i < x+m; ++i){
        for (j = y; j < y+n; ++j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}