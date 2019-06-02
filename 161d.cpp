#include <bits/stdc++.h>
using namespace std;
int i,n,k,ans;
int t1,t2;
vector <int> v[50005];
int mem[50001][501];
void dfs(int u, int last){
    mem[u][0] = 1;
    for (auto v : v[u]){
        if (v == last) continue;
        dfs(v,u);
        for (int j = 1; j <= k; j++) ans += mem[u][j-1]*mem[v][k-j];
        for (int j = 1; j <= k; j++) mem[u][j] += mem[v][j-1];
        
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    dfs(1,0);
    printf("%d",ans);
}