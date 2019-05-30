#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int x; ll val;
    bool operator < (node t) const{
        return val > t.val;
    }
}t;
int V,E;
int i,j,t1,t2,t3;
int A,B,C,D;
vector <node> v[100001];
priority_queue <node> pq;
queue<int> q;
bool visit[100001];
vector <int> vis[100001];
ll dist[100001];
int main(){
    scanf("%d%d",&V,&E);
    for (i = 1; i <= V; i++) dist[i] = LLONG_MAX;
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    scanf("%d%d%d%d",&A,&B,&C,&D);
    dist[A] = 0;
    pq.push({A,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (t.x == B) continue;
        for (i = 0; i < v[t.x].size(); i++){
            int tx = v[t.x][i].x;
            ll tval = v[t.x][i].val+t.val;
            if (dist[tx] > tval){
                vis[tx].clear();
                vis[tx].push_back(t.x);
                dist[tx] = tval;
                pq.push({tx,tval});
            }
            else if (dist[tx] == tval){
                vis[tx].push_back(t.x);
            }
        }
    }
    q.push(B);
    while (!q.empty()){
        int t = q.front(); q.pop();
        visit[t] = true;
        if (t == A) continue;
        for (i = 0; i < vis[t].size(); i++){
            if (visit[vis[t][i]]) continue;
            q.push(vis[t][i]);
        }
    }
    for (i = 1; i <= V; i++) dist[i] = LLONG_MAX;
    dist[C] = 0;
    pq.push({C,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (t.x == D) continue;
        for (i = 0; i < v[t.x].size(); i++){
            int tx = v[t.x][i].x;
            ll tval = v[t.x][i].val+t.val;
            if (dist[tx] > tval && !visit[tx]){
                dist[tx] = tval;
                pq.push({tx,tval});
            }
        }
    }
    printf("%lld",dist[D] == LLONG_MAX ? -1 : dist[D]);
}