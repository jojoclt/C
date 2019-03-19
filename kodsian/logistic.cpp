#include <bits/stdc++.h>
using namespace std;
int p[105];
int V,E;
int s,e,c;
int i,j,k,t1,t2,t3,xx,cc;
int mem[105][105][2];
bool visit[105][105][2];
struct node{
    int x,c,p;
    int f;
    bool operator < (node t) const{
        return p > t.p;
    }
}t;
struct axis{
    int x,val;
};
vector <axis> v[105];
priority_queue <node> q;
int main(){
    scanf("%d",&V);
    for (i = 1; i <= V; i++) scanf("%d",&p[i]);
    scanf("%d%d%d",&s,&e,&c);
    scanf("%d",&E);
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    q.push({s,0,0,0});
    while (!q.empty()){
        t = q.top(); q.pop();
        // printf("now = %d cap = %d price = %d f = %d\n",t.x,t.c,t.p,t.f);
        if (t.x == e && t.c == c){
            printf("%d\n",t.p);
            return 0;
        }
        if (visit[t.x][t.c][t.f]) continue;
        visit[t.x][t.c][t.f] = true;
        if (t.c < c){
            q.push({t.x,t.c+1,t.p+p[t.x],t.f});
            if (!t.f) q.push({t.x,c,t.p,1});
        }
        for (i = 0; i < v[t.x].size(); i++){
            xx = v[t.x][i].x;
            cc = t.c-v[t.x][i].val;
            if (cc >= 0) q.push({xx,cc,t.p,t.f});
        }
    }
}