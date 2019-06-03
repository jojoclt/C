#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int V,E;
int i,j,t,n;
int rnk[N],head[N];
int c(int x){
    if (head[x] == x) return x;
    return head[x] = c(head[x]);
}
void Merge(int u,int v){
    u = c(u), v = c(v);
    if (u == v) return;
    if (rnk[u] < rnk[v]) swap(u,v);
    head[v] = u;
    rnk[u] += rnk[v];

}
int main(){
    scanf("%d%d",&V,&E);
    for (i = 1; i <= V; i++) rnk[i] = 1, head[i] = i;
    for (i = 1; i <= E; i++){
        scanf("%d",&n);
        int last = -1;
        for (j = 1; j <= n; j++){
            scanf("%d",&t);
            if (last != -1) Merge(t,last);
            last = t;
        }
    }

    for (i = 1; i <= V; i++) printf("%d ",rnk[c(i)]);
}