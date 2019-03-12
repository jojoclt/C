#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,c,p;
    bool operator < (node t) const{
        return p > t.p;
    }
}t;
struct coor{
    int x,val;
};
int p[105],mem[105][10005];
int V,E;
int c,s,e;
int i,j,t1,t2,t3,P;
unordered_map <int,vector<coor>> v;
priority_queue <node> pq;
int main(){
    ios::sync_with_stdio(0);
    cin >> V >> E;
    for (i = 0; i < V; i++) cin >> p[i];
    for (i = 0; i < E; i++){
        cin >> t1 >> t2 >> t3;
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    cin >> c >> s >> e;
    fill(&mem[0][0],&mem[V][c],1e9);
    mem[s][0] = 0;
    pq.push({s,0,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        if (t.x == e){
            printf("%d",mem[t.x][t.c]);
            return 0;
        }
        P = t.p;
        for (i = t.c; i <= c; i++){
            for (j = 0; j < v[t.x].size(); j++){
                int xx = v[t.x][j].x;
                int vv = v[t.x][j].val;
                if (vv <= i && mem[xx][i-vv] > P){
                    mem[xx][i-vv] = P;
                    // printf("from %d to %d i = %d >= val %d P = %d\n",t.x,v[t.x][j].x,i,v[t.x][j].val,P);
                    pq.push({xx,i-vv,mem[xx][i-vv]});
                }
            }
            P += p[t.x];
        }
    }
    cout << -99;
    return 0;
}
/*
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
*/