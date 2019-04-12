#include <bits/stdc++.h>
using namespace std;
int tree[100],a[100];
int n,i;
void build(int node, int s, int e){
    if (s == e) tree[node] = a[s];
    else{
        int mid = s+e>>1;
        build(2*node,s,mid);
        build(2*node+1,mid+1,e);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}
int query(int node, int s, int e, int l, int r){
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    int mid = s+e>>1;
    int p1 = query(2*node,s,mid,l,r);
    int p2 = query(2*node+1,mid+1,e,l,r);
    return p1+p2;
}
void update(int node, int s, int e, int id, int val){
    if (s == e){
        a[id] += val;
        tree[node] += val;
    }
    else{
        int mid = s+e>>1;
        if (s <= id && id <= mid) update(2*node,s,mid,id,val);
        else update(2*node+1,mid+1,e,id,val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    build(1,0,n-1);
    // for (i = 1; i < 2*n; i++) printf("%d ",tree[i]);
    cout << query(1,0,n-1,3,5);
}
/*
8
5 8 6 3 2 7 2 6

12
*/