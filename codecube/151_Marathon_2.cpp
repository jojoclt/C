#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
struct node{
    int x,val,shoe;
    bool operator < (node t) const{
        return t.val < val;
    }
}t;
struct node2{
    int x,y;
    bool operator < (node2 t) const{
        return y < t.y || (y == t.y && x < t.x);
    }
}p[100005];
int V,E,K,T;
int i,t1,t2,t3,t4;
priority_queue<node> pq;
vector <node> v[100005];
int mem[100005];
bool dijkstra(int x){
    for (i = 1; i <= V; i++) mem[i] = inf;
    pq.push({1,0,p[x].y});
    while (!pq.empty()){
        t = pq.top(), pq.pop();
        for (i = 0; i < v[t.x].size(); i++){
            int tx = v[t.x][i].x, tval = t.val + v[t.x][i].val;
            if (v[t.x][i].shoe <= t.shoe && mem[tx] > tval && tval <= T){
                mem[tx] = tval;
                pq.push({tx,mem[tx],t.shoe});
            }            
        }
    }
    if (mem[V] == inf) return 0;
    return 1;
}
int main(){
    scanf("%d%d%d%d",&V,&E,&K,&T);
    for (i = 0; i < E; i++){
        scanf("%d%d%d%d",&t1,&t2,&t4,&t3);
        v[t1].push_back({t2,t3,t4});
        v[t2].push_back({t1,t3,t4});
    }
    for (i = 0; i < K; i++) scanf("%d%d",&p[i].x,&p[i].y);
    sort(p,p+K);
    int l = 0,r = K-1,mid;
    bool d;
    int ans = inf,_min=-1;
    while (l <= r){
        mid = (l+r) >> 1;
        d = dijkstra(mid);
        if (d) r = mid-1,_min = p[mid].y;
        else l = mid+1;
    }
    if (_min == -1){
        printf("-1");
        return 0;
    }
    for (i = 0; i < K; i++){
        if (_min <= p[i].y) ans = min(ans,p[i].x);
    }
    printf("%d",ans);
}