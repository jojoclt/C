#include <bits/stdc++.h>
#define clear(x,y) memset(x,y,sizeof(x));
using namespace std;
int n,k;
int cnt;
int i,t1,t2;
bool visit[50005][500];
int mem[50005][500];
vector <int> v[50005];
int dfs(int x, int val){
    if (visit[x][val]) return mem[x][val];
    visit[x][val] = true;
    if (val == k){ ++cnt; return;}
    for (auto c : v[x]) dfs(c,val+1);
    return ;
}
int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    for (i = 1; i <= n; i++){ clear(visit,0); dfs(i,0);}
    printf("%d",cnt/2);
}