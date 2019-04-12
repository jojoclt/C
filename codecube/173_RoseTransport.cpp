#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator < (node t) const{
        return val < t.val;
    }
}t;
int i,j,t1,t2;
int V,E,ans;
int cost[100005];
vector <vector<int>> v;
int head[100005],rnk[100005];
priority_queue <node> pq;
int c(int x){
    if (head[x] == x) return x;
    return head[x] = c(head[x]);
}
int main(){
    scanf("%d%d",&V,&E);
    for (i = 1; i <= V; i++){
        scanf("%d",&cost[i]);
        rnk[i] = 1; head[i] = i;
    }
    for (i = 1; i <= E; i++){
        scanf("%d%d",&t1,&t2);
        pq.push({t1,t2,cost[t1]+cost[t2]});
    }
        
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        t1 = c(t.x), t2 = c(t.y);
        if (t1 == t2) continue;
        if (rnk[t1] > rnk[t2]){
            rnk[t1] += rnk[t2];
            head[t2] = t1;
        }
        else {
            rnk[t2] += rnk[t1];
            head[t1] = t2;
        }
        ans += t.val;
    }
    printf("%d",ans);
}