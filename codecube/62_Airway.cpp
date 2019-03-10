#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,val,go;
    bool operator < (node t) const{
        return val > t.val;
    }
}t;
int V,E,s,e;
int a,b,c,dt;
int i,t1,t2,t3;
priority_queue <node> pq;
vector <node> v[10005];
int mem[10005];
int main(){
    fill(mem,mem+10005,1e9);
    scanf("%d%d",&V,&E);
    scanf("%d%d",&s,&e);
    scanf("%d%d%d%d",&a,&b,&c,&dt);
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
    }
    mem[s] = 0;
    pq.push({s,0,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        for (i = 0; i < v[t.x].size(); i++){
            if (t.x == a && !t.go && t.val <= dt){
                if (mem[b] > mem[a]+c){
                    mem[b] = mem[a]+c;
                    pq.push({b,mem[b],1});
                }
            }
            if (mem[v[t.x][i].x] > mem[t.x]+v[t.x][i].val){
                mem[v[t.x][i].x] = mem[t.x]+v[t.x][i].val;
                pq.push({v[t.x][i].x,mem[v[t.x][i].x],t.go});
            }
        }
    }
    printf("%d",mem[e]);
}
