#include <bits/stdc++.h>
using namespace std;
int V,E;
int mem[1005][105];
int p[105];
bool visit[105];
int i,j,t1,t2,t3;
int C,s,e;
struct node{
    int x,y,val;
    bool operator < (node t) const{
        return val > t.val;
    }
};
struct value{
    int x,c,p;
    bool operator < (value t) const{
        return p > t.p;
    }
}t;
priority_queue <value> pq;
queue <value> q;
vector <node> v[1000];
vector <value> go[1000];
void isReachable(){
    for (i = 0; i < V; i++){
        memset(visit,0,sizeof(visit));
        q.push({i,0});
        while (!q.empty()){
            t = q.front(); q.pop();
            visit[t.x] = true;
            for (j = 0; j < v[t.x].size(); j++){
                int xx = v[t.x][j].x;
                int vv = t.c+v[t.x][j].val;
                if (visit[xx]) continue;
                if (vv <= C){
                    go[i].push_back({xx,vv});
                    q.push({xx,vv});
                }
            }
        }
    }
}
void destinationReached(){
    fill(&mem[0][0],&mem[1004][104],1e9);
    mem[s][0] = 0;
    pq.push({s,0,0});
    while (!pq.empty()){
        t = pq.top(); pq.pop();
        for (i = 0; i < go[t.x].size(); i++){
            int gx = go[t.x][i].x;
            int gv = go[t.x][i].c;
            if (t.c < gv){
                int cc = gv-t.c;
                int pp = p[t.x]*(gv-t.c);
                if (mem[gx][cc] > pp){
                    mem[gx][cc] = pp;
                    pq.push({gx,cc,pp});
                    printf("mem[%d][%d] = %d\n",gx,cc);
                }
            }
            else{
                int cc = t.c-gv;
                if (mem[gx][cc] > t.p){
                    mem[gx][cc] = t.p;
                    pq.push({gx,cc,t.p});
                    printf("mem[%d][%d] = %d\n",gx,cc);
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin >> V >> E;
    for (i = 0; i < V; i++) cin >> p[i];
    for (i = 0; i < E; i++){
        cin >> t1 >> t2 >> t3;
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    cin >> C >> s >> e;
    isReachable();
    for (i = 0; i < V; i++){
        for (j = 0; j < go[i].size(); j++)
            printf("go[%d][%d] = %d CAP = %d\n",i,j,go[i][j].x,go[i][j].c);
        cout << endl;
    }
    return 0;
    destinationReached();
    cout << mem[e][0];
}