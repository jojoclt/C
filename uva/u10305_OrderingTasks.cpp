#include <bits/stdc++.h>
using namespace std;
int V,E;
int i,t1,t2;
bool visit[100];
unordered_map<int,vector<int>> v;
stack <int> st;
void dfs(int x){
    visit[x] = true;
    for (int j = 0; j < v[x].size(); j++){
        if (visit[v[x][j]]) continue;
        dfs(v[x][j]);
    }
    st.push(x);
}
int main(){
    while (scanf("%d%d",&a,&b),a&&b){
        v[a].push_
    }
    for (i = 0; i < E; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
    }
    for (i = 1; i <= V; i++){
        if (visit[i]) continue;
        dfs(i);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
/*
7 7
1 3
2 3
3 4
2 5
4 6
5 6
6 7
*/