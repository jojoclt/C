#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,val;
    bool operator < (node t) const{
        return val > t.val;
    }
}t;
int V,c = 0;
vector <node> v[100005];
int t1,t2,t3,i;
bool visit[100005];
int mem[100005];
priority_queue <node> pq;
int main(){
//    return 0;
    fill(mem,mem+100005,1e9);
    scanf("%d",&V);
    for (i = 0; i < V-1; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    pq.push({1,0});
    mem[1] = 0;
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        for (i = 0; i < v[t.x].size(); i++){
            if (mem[v[t.x][i].x] > mem[t.x]+v[t.x][i].val){
                mem[v[t.x][i].x] = mem[t.x]+v[t.x][i].val;
                pq.push({v[t.x][i].x,mem[v[t.x][i].x]});
            }
        }
    }
    for (i = 1; i <= V; i++){
        c = max(c,mem[i]);
    }
    printf("%d",c);
}
