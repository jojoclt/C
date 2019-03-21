#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator < (node t) const{
        return val > t.val;
    }
}t;
priority_queue <node> pq;
vector <node> v[50005];
set <int> s;
int n,m,k;
int type[50005],head[50005];
int i,t1,t2,t3;
int l,r,mid;
int c(int x){
    if (head[x] != x) return head[x] = c(head[x]);
    return head[x] = x;
}
int main(){
    s.insert(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++){
        cin >> type[i];
        head[i] = i;
    }
    for (i = 0; i < m; i++){
        cin >> t1 >> t2 >> t3;
        pq.push({t1,t2,t3});
        s.insert(t3);
    }
    l = 0; r = s.size(); mid = 1;
    printf("%d",mid);
}