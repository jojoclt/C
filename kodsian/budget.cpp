#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,val;
    bool operator < (node t) const{
        if (x != t.x) return val > t.val;
        return x > t.x;
    }
}t,vv;
int V,E;
int track[10005];
int dijk1[10005],dijk2[10005];
int i,t1,t2,t3;
int s,e,T;
int x,pos;
vector <node> v[10005];
priority_queue <node> q;
int main(){
    scanf("%d%d",&V,&E);
    for (i = 0; i <= V; i++) dijk1[i] = dijk2[i] = 1e9;
    scanf("%d%d%d",&s,&e,&T);
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    dijk1[s] = dijk2[e] = 0;
    q.push({s,0});
    while (!q.empty()){
        t = q.top(); q.pop();
        for (i = 0; i < v[t.x].size(); i++){
            vv = v[t.x][i];
            if (dijk1[vv.x] > dijk1[t.x] + vv.val){
                dijk1[vv.x] = dijk1[t.x] + vv.val;
                q.push({vv.x,dijk1[vv.x]});
            }
        }
    }
    if (dijk1[e] <= T){
        printf("%d %d 0",e,dijk1[e]);
        return 0;
    }
    q.push({e,0});
    while (!q.empty()){
        t = q.top(); q.pop();
        if (dijk1[t.x] <= T){
            printf("%d %d %d",t.x,dijk1[t.x],dijk2[t.x]);
            return 0;
        }
        for (i = 0; i < v[t.x].size(); i++){
            vv = v[t.x][i];
            if (dijk2[vv.x] > dijk2[t.x] + vv.val){
                dijk2[vv.x] = dijk2[t.x] + vv.val;
                q.push({vv.x,dijk2[vv.x]});
            }
        }
    }
}