#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator < (node t) const{
        if (x != t.x) return x < t.x;
        return y < t.y;
    }
};
const int INF = 1e9;
int n,k;
int i,j,t1,t2,vv,pos;
int ans;
vector <node> v;
priority_queue <int> pq;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v.push_back({t1,t2,INF});
    }
    sort(v.begin(),v.end());
    for (i = 0; i < n-1; i++){
        for (j = i+1; j < n; j++){
            vv = abs(v[i].x-v[j].x) + abs(v[i].y-v[j].y);
            if (vv < v[i].val){
                pos = j;
                v[i].val = vv;
            }
            else if (vv == v[i].val){
                if (vv < v[j].val) v[j].val = vv;
                // ans += v[i].val;
                // pq.push(v[i].val);
            }
        }
        ans += v[i].val;
        pq.push(v[i].val); 
    }
    for (i = 0; i < k-1; i++){
        ans -= pq.top(); pq.pop();
    }

    printf("%d",ans);
}