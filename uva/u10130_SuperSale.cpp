#include <bits/stdc++.h>
using namespace std;
int T,i,j,t,n,q,cnt;
int mem[1005][35];
int p[1005],w[1005];
void Clear(){
    for (i = 0; i < 1005; i++) p[i] = w[i] = 0;
    fill(&mem[0][0],&mem[1005][0],0);
    cnt = 0;
}
int f(int x, int c){
    if (x == n || c == 0) return 0;
    if (mem[x][c]) return mem[x][c];
    mem[x][c] = f(x+1,c);
    if (w[x] <= c) return mem[x][c] = max(mem[x][c], p[x] + f(x+1,c-w[x]));
    return mem[x][c];
}
int main(){
    scanf("%d",&T);
    while(T--){
        Clear();
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d%d",&p[i],&w[i]);
        scanf("%d",&q);
        for (i = 0; i < q; i++){
            scanf("%d",&t);
            cnt += f(0,t);
        }
        printf("%d\n",cnt);
    }
}