#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct node{
    int x,val;
    bool operator < (node t) const{
        return val < t.val;
    }
}t;
int V,E;
int i,t1,t2,t3,xx,vv,ans=1e9;
int s,e,cap;
int mem[2505];
vector <node> v[2505];
priority_queue <node> pq;
int main(){
    scanf("%d%d",&V,&E);
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        if (t3 == 1) continue;
        v[t1].push_back({t2,t3-1});
        v[t2].push_back({t1,t3-1});
    }
    scanf("%d%d%d",&s,&e,&cap);
    mem[s] = INF;
    pq.push({s,INF});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (t.x == e){
            printf("%d",((cap-1)/t.val)+1);
            return 0;
        }
        for (i = 0; i < v[t.x].size(); i++){
            xx = v[t.x][i].x;
            vv = v[t.x][i].val;
            if (mem[xx] >= min(t.val,vv)) continue;
            mem[xx] = min(t.val,vv);
            pq.push({xx,mem[xx]});
        }
    }
}