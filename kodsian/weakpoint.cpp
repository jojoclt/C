#include <bits/stdc++.h>
using namespace std;
int n,c;
int i,t1,t2;
bool visit[500005];
int cnt;
vector <int> v[500005];
void dfs(int s, int x){
    if (visit[s]) return;
    visit[s] = true;
    ++cnt;
    for (auto u : v[s])
        if (u != x) dfs(u,x);
}
int main(){
    scanf("%d%d",&n,&c);
    for (i = 0; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    int node = 1e9, val = 0;
    for (i = 1; i <= n; i++){
        cnt = 0;
        memset(visit,0,sizeof(visit));
        if (i == c) continue;
        dfs(c,i);
        // printf("%d= %d\n",i,cnt);
        // continue;
        t1 = n-cnt-1;
        if (val < t1){
            val = t1;
            node = min(node,i);
        }
    }
    if (node == 1e9 && val == 0){
        if (c == 1) printf("2\n0");
        else printf("1\n0");
    }
    else printf("%d\n%d",node,val);

}