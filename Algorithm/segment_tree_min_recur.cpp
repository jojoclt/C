#include <bits/stdc++.h>
using namespace std;
int n,i;
int a[100],tree[100];
void build(int node, int s, int e){
    if (s == e) tree[node] = a[s];
    else{
        int mid = s+e>>1;
        build(node*2,s,mid);
        build(node*2+1,mid+1,e);
        tree[node] = min(tree[node*2],tree[node*2+1]);
    }
}
int query(int node, int s, int e, int l, int r){
    if (e < l || r < s) return INT_MAX;
    if (l <= s && e <= r) return tree[node];
    int mid = s+e>>1;
    int q1 = query(node*2,s,mid,l,r);
    int q2 = query(node*2+1,mid+1,e,l,r);
    return min(q1,q2);
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    build(1,0,n-1);
    // for (i = 1; i < n*2; i++) printf("%d ",tree[i]);
    cout << query(1,0,n-1,1,2);
}

/*
4
-1 2 4 0
*/