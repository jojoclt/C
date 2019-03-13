#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
};
const int INF = 1e9;
int n,k;
int i,j,t1,t2,vv,pos,mi;
int ans;
vector <node> v;
priority_queue <int> pq;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v.push_back({t1,t2,INF});
    }
    for (i = 0; i < n-1; i++){
        mi=1e9;
        for (j = i+1; j < n; j++){
            vv = abs(v[i].x-v[j].x) + abs(v[i].y-v[j].y);
            if(vv<v[j].val) v[j].val=vv;
            if(v[j].val < mi) mi=v[j].val,pos=j;
           
        }
        ans += mi;
        pq.push(mi); 
        swap(v[i+1],v[pos]);
    }
    for (i = 0; i < k-1; i++){
        ans -= pq.top(); pq.pop();
    }

    printf("%d",ans);
} 