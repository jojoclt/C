#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val;
    bool operator < (node t) const{
        return val < t.val;
    }
}t;
const int N = 2e5+2;
int n,e,k,head[N];
int i,t1,t2,cnt;
bool visit[N];
priority_queue <node> pq;
int h(int x){
    if (head[x] == x)return x;
    return head[x] = h(head[x]);
}
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> e >> k;
    for (i = 0; i < n; i++) head[i] = i;
    for (i = 0; i < e; i++){
        cin >> t1 >> t2;
        pq.push({t1,t2,(t1 == 1 || t2 == 1)? 1: 0});
        if (t1 == 1 || t2 == 1) cnt++;
    }
    if (cnt < k) {
        cout << "NO";
        return 0;
    }
    cnt = 0;
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (h(t.x) != h(t.y)){
            head[h(t.x)] = h(t.y);
            q.push({t.x,t.y});
            cout << t.x << " " <<t.y<<endl;
            cnt++;
        }
        if (cnt == k) while (pq.top().val && !pq.empty()) pq.pop();
        
    }
    cout << cnt;
    if (cnt != n-1){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    while (!q.empty()){
        t = q.front(); q.pop();
        printf("\n%d %d",t.x,t.y);
    }

}