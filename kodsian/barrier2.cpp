#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int n,w,i;
int a[6000005];
struct Node{
    ll sum, maxleftsum, maxrightsum, maxsum;
    int l,r,len;

}tree[24000005],res;
int f(int x){
    return 1 << (int)(ceil(log2(n)) - floor(log2(x)));
}
int W; ll val;
Node Merge(Node &l, Node &r, int x){
    Node p;
    p.sum = l.sum + r.sum;
    p.maxleftsum = max(l.maxleftsum, l.sum + r.maxleftsum);
    p.maxrightsum = max(r.maxrightsum, r.sum + l.maxrightsum);
    p.maxsum = max({l.maxsum, r.maxsum, l.maxrightsum + r.maxleftsum});

    if (p.maxleftsum == l.maxleftsum) p.l = l.l;
    else p.l = x + r.l;
    if (p.maxrightsum == r.maxrightsum) p.r = r.r;
    else p.r = x + l.r;

    if (p.maxsum == l.maxsum) p.len = l.len;
    else if (p.maxsum == r.maxsum) p.len = r.len;
    else p.len = l.r+r.l;
    return p;
}
void build(int node, int s, int e){
    if (s == e) {
        tree[node].sum = tree[node].maxleftsum = tree[node].maxrightsum = tree[node].maxsum = a[s];
        tree[node].l = tree[node].r = tree[node].len = 1;
        return;
    }
    int mid = s+e>>1;
    build(node<<1,s,mid);
    build(node<<1|1,mid+1,e);
    tree[node] = Merge(tree[node<<1],tree[node<<1|1],f(node<<1));
}
Node query(int node, int s, int e, int l, int r){
    if (e < l || r < s) {
        Node nullNode;
        return nullNode;
        // return (Node){0,MIN,MIN,MIN};
    }
    if (l <= s && e <= r) return tree[node];
    int mid = s+e>>1;
    Node left = query(node<<1,s,mid,l,r);
    Node right = query(node<<1|1,mid+1,e,l,r);
    Node result = Merge(left,right,f(node<<1));
    return result;
}
int main(){
    scanf("%d",&n);
    scanf("%d",&w);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    build(1,0,n-1);
//    for (i = 1; i < 2*n; i++) printf("%d: %d\n",i,f(i));
//    return 0;
    for (i = 0; i < n-w+1; i++){
        res = query(1,0,n-1,i,i+w-1);
        cout << res.maxsum << " ";
        continue;
        if (val < res.maxsum){
            val = res.maxsum;
            W = res.len;
        }
        else if (val == res.maxsum){
            if (W > res.len) W = res.len;
        }
    }
    if (!val) printf("0\n0");
    else {
        printf("%lld\n%d",val,W);
    }
}
