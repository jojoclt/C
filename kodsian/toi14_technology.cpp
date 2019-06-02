#include <bits/stdc++.h>
using namespace std;
int n,hitech,lim;
int i,j,k,t,p;
int cnt = 0,ans;
vector <int> tech[10005],v[100005];
bool visit[100005],chk[100005];
void dfs(int x){
    if (visit[x]) return ;
    if (chk[x]) {
        cnt = 1e9;
        return ;
    }
    chk[x] = true, ++cnt;
    for (auto c : v[x]) dfs(c);
    visit[x] = true;
    return ;
}
int main(){
    scanf("%d%d%d",&n,&hitech,&lim);
    for (i = 1; i <= n; i++){
        scanf("%d",&t);
        tech[t].push_back(i);
        scanf("%d",&p);
        for (j = 0; j < p; j++){
            scanf("%d",&t);
            v[i].push_back(t);
        }
    }
    for (j = 1; j <= hitech; j++){
        memset(chk,false,sizeof(chk));
        for (k = 0; k < (int)tech[j].size(); k++) dfs(tech[j][k]);
        if (cnt <= lim) ans = j;
        else break;
    }
    if (ans) printf("%d",ans);
    else printf("-1");
}