#include <bits/stdc++.h>
#define inf 2e9
using namespace std;
struct shoe{
    int x,y;
};
struct node{
    int x,dan,tim;
    bool operator < (node t) const{
        return t.dan < dan || (t.dan == dan && t.tim < tim);
    }
}t;
int V,E,k,T;
int i,t1,t2,t3,t4;
int val = inf;
bool visit[100005];
int tim[100005];
vector <node> v[100005];
priority_queue<node> pq;
vector <shoe> p;
int mem[2000005];
int h(int a, int b){
    if (a == b) return a + b;
    if (a > b) return (a-b)*3 + a + 314;
    else return (a+b)*5 +b +971;
}
int main(){
    scanf("%d%d%d%d",&V,&E,&k,&T);
    for (i = 0; i < E; i++){
        scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
        v[t1].push_back({t2,t3,t4});
        v[t2].push_back({t1,t3,t4});
    }
    for (i = 0; i < k; i++){
        scanf("%d%d",&t1,&t2);
        p.push_back({t2,t1});
    }
    for (i = 1; i <= V; i++) tim[i] = inf;
    tim[V] = 0;
    pq.push({V,0,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (visit[t.x]) continue;
        visit[t.x] = true;
        for (i = 0; i < v[t.x].size(); i++){
            int tx = v[t.x][i].x, tt = t.tim+v[t.x][i].tim;
            if (visit[tx]) continue;
            if (tim[tx] > tt){
                tim[tx] = tt;
                pq.push({tx,0,tim[tx]});
            }
        }
    }
    // for (i = 1; i <= V; i++) mem[i] = inf;
    // mem[1] = 0;
    pq.push({1,0,0});
    memset(visit,false,sizeof(visit));
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (t.x == V && t.dan < val){
            val = t.dan;
            continue;
        }
        t4 = h(t.x,t.dan);
        if (mem[t4] && mem[t4] <= t.tim) continue;
        mem[t4] = t.tim; 
        for (i = 0; i < v[t.x].size(); i++){
            int tx = v[t.x][i].x, tt = t.tim + v[t.x][i].tim, tdan = max(t.dan,v[t.x][i].dan);
            if (tt + tim[tx] <= T){
                pq.push({tx,tdan,tt});
            }
        }
    }
    t4 = inf;
    for (i = 0; i < k; i++){
        if (p[i].x >= val){
            t4 = min(t4,p[i].y);
        }
    }
    printf("%d", t4 == inf ? -1: t4);
}