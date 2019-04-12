#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,w,i,X,t1,t2;
int a[50005],minW;
ll result=0;
unordered_map<ll,int> m;
struct Node{
    ll sum, maxleftsum, maxrightsum, maxsum;
    // int l,r,length;
    // Node(){
    //     l = r = length = 1;
    // }

}tree[4*50001];
int f(int x){
    return pow(2,X-x);
}
Node Merge(Node l, Node r, int node){
    Node p;
    p.maxleftsum = max(l.maxleftsum, l.sum + r.maxleftsum);
    p.maxrightsum = max(r.maxrightsum, r.sum + l.maxrightsum);
    p.sum = l.sum + r.sum;
    p.maxsum = max({l.maxsum, r.maxsum, l.maxrightsum + r.maxleftsum});

    // if (p.maxleftsum == l.sum + r.maxleftsum) p.l = node+r.l; else p.l = l.l;
    // if (p.maxrightsum == r.sum + l.maxrightsum) p.r = node+l.r; else p.r = r.r;

    // if (!m[p.maxsum]) m[p.maxsum] = 1e9;
    // else{
    //     if (p.maxsum == l.maxsum) m[p.maxsum] = min(m[p.maxsum],1);
    //     else if (p.maxsum == r.maxsum) m[p.maxsum] = min(m[p.maxsum],1);
    //     else m[p.maxsum] = min(m[p.maxsum],l.r+r.l);
    // }
    // cout << p.maxsum << " " <<m[p.maxsum]<<endl;
    return p;
}
void build(int node, int s, int e){
    if (s == e) {
        tree[node].sum = a[s];
        tree[node].maxleftsum = a[s];
        tree[node].maxrightsum = a[s];
        tree[node].maxsum = a[s];
        return;
    }
    int mid = s+e>>1;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    tree[node] = Merge(tree[2*node],tree[2*node+1],f(node));
}
Node query(int node, int s, int e, int l, int r){
    if (e < l || r < s) {
        Node nullNode;
        return nullNode;
    }
    if (l <= s && e <= r) return tree[node];
    int mid = s+e>>1;
    Node left = query(node*2,s,mid,l,r);
    Node right = query(node*2+1,mid+1,e,l,r);
    Node result = Merge(left,right,0);
    return result;
}
ll q(int s, int e){
    Node result = query(1,0,n-1,s,e);
    return result.maxsum;
}
int main(){
    scanf("%d",&n);
    // X = ceil(log2(n));
    // minW = w;
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    build(1,0,n-1);
    scanf("%d",&w);
    for (i = 0; i < w; i++){
        scanf("%d%d",&t1,&t2);
        printf("%lld\n",q(t1-1,t2-1));
    }
    // for (auto c : m) cout << c.first << " " << c.second<<endl;
    // // Node x = query(1,0,n-1,0,7);
    // printf("%lld",result);
}

/*
4 99
-1 2 4 0
*/