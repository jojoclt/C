#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 2e5+2;
int n,e,k;
int i,t,t1,t2,S,cnt;
vector <int> v1;
bool visit[N],visit1[N],isExist;
queue <int> q;
stack <int> c,tc;
queue <pair<int,int>> ans;
unordered_map <int,vector<int>> v;
void fun(){
    cout << "YES";
    while (!ans.empty()){
        pii T = ans.front(); ans.pop();
        printf("\n%d %d",T.first,T.second);
    }
    return ;
}
void bfs(){
    while (!ans.empty()) ans.pop();
    cnt = 0;
    tc = c;
    while (!tc.empty()){
        t = tc.top(); tc.pop();
        cnt++;
        q.push(t);
    }
    while (!q.empty()){
        t = q.front(); q.pop();
        visit[t] = true;
        for (i = 0; i < v[t].size(); i++){
            if (visit[v[t][i]]) continue;
            visit[v[t][i]] = true;
            ans.push(make_pair(t,v[t][i]));
            cnt++;
        }
    }
    cout << cnt << endl;
    if (cnt == n-1) fun();
}
void dfs(int u){
    if (isExist) return;
    if (u == S){
        bfs();
        fill(visit,visit+n,false);
        return ;
    }
    c.push(v1[u]);
    dfs(u+1);
    c.pop();
    dfs(u+1);

}
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> e >> k;
    for (i = 0; i < e; i++){
        cin >> t1 >> t2;
        if (t1 == 1){
            if (visit1[t1]) continue;
            visit1[t1] = true;
            v1.push_back(t2); 
        }
        else if (t2 == 1){
            if (visit1[t2]) continue;
            visit1[t2] = true;
            v1.push_back(t1);
        }
        else {
            v[t1].push_back(t2);
            v[t2].push_back(t1);
        }
    }
    S = v1.size();
    dfs(0);
    if (!isExist) cout << "NO";

}
