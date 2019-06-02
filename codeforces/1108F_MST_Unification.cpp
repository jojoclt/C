#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator < (node t) const{
        return val < t.val;
    }
}t;
const int N = 2e5+1;
int head[N],rnk[N];
int V,E;
int i,t1,t2,t3;
vector <node> pq;
int c(int x){
    if (head[x] == x) return x;
    return head[x] = c(head[x]);
}
bool Merge(int u, int v){
    u = c(u), v = c(v);
    if (u == v) return false;
    if (rnk[u] < rnk[v]) swap(u,v);
    rnk[u] += rnk[v];
    head[v] = u;
    return true;
}
int main(){
    scanf("%d%d",&V,&E);
    for (i = 1; i <= V; i++) rnk[i] = 1, head[i] = i;
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        pq.push_back({t1,t2,t3});
    }
    int ans = 0;
    sort(pq.begin(),pq.end());
    for (i = 0; i < E; ++i){
        int j = i;
        while (j < E && pq[i].val == pq[j].val) ++j;
        int cnt = j-i;
        for (int k = i; k < j; k++) if (c(pq[k].x) == c(pq[k].y)) --cnt;
        for (int k = i; k < j; k++)
            cnt -= Merge(pq[k].x,pq[k].y);
        
        ans += cnt;
        i = j-1;
    }
    printf("%d",ans);
}