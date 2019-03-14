#include <bits/stdc++.h>
using namespace std;
int n,k;
int i,t,t1,t2;
bool visit[2005];
int dist[2005];
unordered_map <int,vector<int>> v;
queue <int> q;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < k; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    for (i = 0; i <= 2000; i++){
        sort(v[i].begin(),v[i].end());
        dist[i] = 1e9;
    }
    q.push(1);
    dist[1] = 1;
    while (!q.empty()){
        t = q.front(); q.pop();
        visit[t] = true;
        for (i = 0; i < v[t].size(); i++){
            if (visit[v[t][i]]) continue;
            dist[v[t][i]] = dist[t]+1;
            q.push(v[t][i]);
        }
    }
}