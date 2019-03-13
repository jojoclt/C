#include <bits/stdc++.h>
using namespace std;
int V,E;
int i,a,b;
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
    while (scanf("%d%d",&V,&E),V||E){
        for (i = 0; i < E; i++){
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
        }
        for (i = 0; i <= V; i++){
            if (visit[i]) continue;
            dfs(i);
        }
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        printf("\n");
        memset(visit,0,sizeof(visit));
    }
}
/*
5 4 1 2 2 3 1 3 1 5 0 0
*/