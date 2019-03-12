#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,cap,p;
    bool operator < (node t) const{
        return p > t.p;
    }
}t;
struct coor{
    int x,val;
};
int p[1005];
bool visit[1005][105];
int V,E;
int c,s,e;
int i,j,t1,t2,t3,P;
bool flag;
//unordered_map <int,vector<coor>> v;
priority_queue <node> pq;
vector <coor> v[1005];
void Clear(){
    flag = false;
    fill(&visit[0][0],&visit[1004][104],false);
    while (!pq.empty()) pq.pop();
}
int main(){
//    freopen("in.txt","r",stdin);
//     freopen("out.txt","w",stdout);

    cin >> V >> E;
    for (i = 0; i < V; i++) cin >> p[i];
    for (i = 0; i < E; i++){
        cin >> t1 >> t2 >> t3;
        v[t1].push_back({t2,t3});
        v[t2].push_back({t1,t3});
    }
    int QQQ;
    cin >> QQQ;
    while (QQQ--){
        Clear();
        cin >> c >> s >> e;
        pq.push({s,0,0});
        while (!pq.empty()){
            t = pq.top(); pq.pop();
            if (t.x == e){
                printf("%d\n",t.p);
                flag = true;
                break;
            }
            if (visit[t.x][t.cap]) continue;
            visit[t.x][t.cap] = true;
            if (t.cap < c) pq.push({t.x,t.cap+1,t.p+p[t.x]});
            for (int i = 0; i < v[t.x].size(); i++){
                int xx = v[t.x][i].x;
                int cc = t.cap-v[t.x][i].val;
                if (cc >= 0) pq.push({xx,cc,t.p});
            }
        }
//        cout << QQQ<<endl;
        if (!flag) cout << "impossible\n";
    }
    //return 0;
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
