#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,val;
    bool operator < (node t) const{
        return val > t.val;
    }
}t;
int V,E;
int t1,t2,t3,i;
bool visit[105];
int mem[105];
priority_queue <node> pq;
vector <node> v[105];
int main(){
    fill(mem,mem+105,1e9);
    scanf("%d%d",&V,&E);
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    pq.push({1,0});
    //mem[1] = 0;
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        mem[t.x] = min(mem[t.x],t.val);
        for (i = 0; i < v[t.x].size(); i++){
            if (mem[v[t.x][i].x] > t.val+v[t.x][i].val){
                mem[v[t.x][i].x] = t.val+v[t.x][i].val;
                pq.push({v[t.x][i].x,mem[v[t.x][i].x]});
            }
        }
    }
    for (i = 1; i <= V; i++){
        printf("mem[%d] = %d\n",i,mem[i]);
    }
}
