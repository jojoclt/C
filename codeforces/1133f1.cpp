#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+2;
unordered_map <int,vector<int>> v;
int a[N];
int n,e;
int i,t,t1,t2,high = 0,highP;
bool visit[N];
queue <int> q;
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> e;
    for (i = 0; i < e; i++){
        cin >> t1 >> t2;
        if (++a[t1] > high) high = a[t1],highP = t1;
        if (++a[t2] > high) high = a[t2],highP = t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
//    printf("\n\n\n");
    q.push(highP);
    while (!q.empty()){
        t = q.front(); q.pop();
        visit[t] = true;
        for (i = 0; i < v[t].size(); i++){
            if (visit[v[t][i]]) continue;
            visit[v[t][i]] = true;
            q.push(v[t][i]);
            printf("%d %d\n",t,v[t][i]);
        }
    }
}