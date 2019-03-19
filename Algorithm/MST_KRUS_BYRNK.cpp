#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator < (node a) const{
        return a.val > val;
    }
};
priority_queue<node> heap;
int head[200001],rnk[200001],u,v;
long long ans = 0;
int c(int x){
    if (head[x] != x) return head[x] = c(head[x]);
    else return head[x];
}

int main(){
    int c1,c2,c3;
    int n,m,i;
    scanf("%d%d",&n,&m);
    for (i = 0; i < m; i++){
        scanf("%d%d%d",&c1,&c2,&c3);
        heap.push({c1,c2,c3});
    }
    for(i = 0; i < 200001; i++) head[i] = i,rnk[i] = 1;
    while (!heap.empty()){
        node t = heap.top(); heap.pop();
        u = c(t.x), v = c(t.y);
        if (u == v) continue;
        if (rnk[u] > rnk[v]){
            rnk[u] += rnk[v];
            head[v] = u;
        }
        else{
            rnk[v] += rnk[u];
            head[u] = v;
        }
        ans += t.val-1;
    }
    printf("%lld",ans);
}
