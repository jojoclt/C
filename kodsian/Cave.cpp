#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,val,p;
    bool operator < (node t) const{
        if (val == t.val) return t.p < p;
        return t.val < val;
    }
}t;
int V,S,cur,E;
int t1,t2,t3,i,j,q;
vector <node> v[2005],mem[2005];
priority_queue <node> pq;
bool Go;
int main(){
    scanf("%d%d%d%d",&V,&S,&cur,&E);
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3});
    }
    pq.push({S,0,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        for (auto c : v[t.x]){
            Go = true;
            int tv = t.val+c.val, tp = t.p+1;
            for (auto u : mem[c.x]){
                if (tv > u.val && tp > u.p) Go = false;
            }
            if (Go){
                mem[c.x].push_back({-1,tv,tp});
                pq.push({c.x,tv,tp});
            }
        }
    }
    scanf("%d",&q);
    // q=1;
    while (q--){
        int mv = 1e9;
        scanf("%d",&t1);
        for (auto c : mem[cur]){
            mv = min(mv,t1*--c.p+c.val);
        }
        printf("%d ",mv);
    }
}