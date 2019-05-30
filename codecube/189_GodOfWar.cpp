#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,val;
    int k;
    bool operator < (node t) const{
        return val > t.val;
    }
}t;
int V,E;
int i,t1,t2,t3,sum;
int s,e;
priority_queue<node> pq;
vector <node> v[100005];
int mem[100005][2];
int main(){
    scanf("%d%d%d%d",&V,&E,&s,&e);
    for (i = 0; i < V; i++){
        mem[i][0] = mem[i][1] = 1e9;
    } 
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
        sum += t3;
    }
    mem[s][0] = 0;
    pq.push({s,0,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        for (i = 0; i < v[t.x].size(); i++){
            int tx = v[t.x][i].x;
            int tval = t.val+v[t.x][i].val;
            if (mem[tx][t.k] > tval){
                mem[tx][t.k] = tval;
                pq.push({tx,tval,t.k});
            }
            if (!t.k && mem[tx][1] > t.val){
                mem[tx][1] = t.val;
                pq.push({tx,t.val,1});
            }
        }
    }
    printf("%d",sum-mem[e][1]);
}