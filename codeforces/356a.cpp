#include <bits/stdc++.h>
using namespace std;

const int maxn = 300003;
int head[maxn],col[maxn];
int find(int x){
    if (head[x] == x) return x;
    return head[x] = find(head[x]);
}
void disjoint(int l, int r, int c){
    while (l <= r){
        int x = find(l);
        if (x == l){
            col[l] = c;
            head[l] = l+1;
        }
        l = head[l];
    }
}
int main(){
    int i,n,m;
    scanf("%d%d",&n,&m);
    for (i = 1; i <= n+1; i++) head[i] = i;
    while (m--){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        disjoint(l,x-1,x);
        disjoint(x+1,r,x);
    }
    for (i = 1; i <= n; i++) printf("%d ",col[i]);
}