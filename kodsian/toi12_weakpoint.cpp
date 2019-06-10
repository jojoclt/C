#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5+5;
int n,s;
int i,t1,t2,S;
vector <int> v[N];
bool visit[N];
int h[N],mem[N],_max = -1,ans;
bool dfs(int x){
    bool g = true;
    visit[x] = true;
    h[x] = S;
    for (auto c : v[x]){
        if (!visit[c]){
            bool t = dfs(c);
            if (t) mem[x] += mem[c]+1;
            g &= t;
        }
        else if (h[x] != h[c]) g = false;//cycle
    }
    return g;
}
int main(){
    scanf("%d%d",&n,&s);
    for (i = 0; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].pb(t2);
        v[t2].pb(t1);
    }
    visit[s] = true;
    for (auto c : v[s]) h[c] = c,visit[c] = true;
    for (auto c : v[s]){
        S = c;
        h[s] = S;
        dfs(S);
    }
    for (i = 1; i <= n; i++){
        if (i == s) continue;
        if (_max < mem[i]) _max = mem[i], ans = i;
    }
    printf("%d\n%d",ans,_max);
}