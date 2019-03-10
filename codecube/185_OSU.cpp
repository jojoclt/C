#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int x;
    int cnt;
    ll val;
    bool operator < (node t) const{
        return val > t.val;
    }
}t;
struct axis{
    int x,val;
}vt;
int V,E,T;
int s,e;
bool visit[10005][10];
ll mem[10005][10];
vector <axis> v[10005];
int i,t1,t2,t3;
priority_queue <node> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E >> T;
    cin >> s >> e;
    for (i = 0; i < E; i++){
        cin >> t1 >> t2 >> t3;
        v[t1].push_back({t2,t3});
    }
    fill(&mem[0][0],&mem[10004][9],1e17);
    mem[s][1] = 0;
    q.push({s,1,0});
    while (!q.empty()){
        t = q.top(); q.pop();
        //cout << t.x << " " <<t.cnt<<endl;
        if (visit[t.x][t.cnt]) continue;
        visit[t.x][t.cnt] = true;
        int td = (t.cnt+1)%T;
        for (i = 0; i < v[t.x].size(); i++){
            vt = v[t.x][i];
            if (visit[vt.x][td]) continue;
            if (t.val + vt.val < mem[vt.x][td]){
                mem[vt.x][td] = t.val+vt.val;
                q.push({vt.x,td,mem[vt.x][td]});
            }
        }
    }
    printf("%lld", mem[e][0] == 1e17 ? -1 : mem[e][0]);
}
