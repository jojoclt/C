#include <bits/stdc++.h>
#define MIN -1000000000
using namespace std;
int n,w,i,t1,t2;
int a[50005];
int result=0;
struct Node{
    int sum, maxleftsum, maxrightsum, maxsum;
    Node(){
        sum = 0;
        maxleftsum = maxrightsum = maxsum = MIN;
    }
    
}tree[4*50005];

Node Merge(Node l, Node r){
    Node p;
    p.maxleftsum = max(l.maxleftsum, l.sum + r.maxleftsum);
    p.maxrightsum = max(r.maxrightsum, r.sum + l.maxrightsum);
    p.sum = l.sum + r.sum;
    p.maxsum = max({l.maxsum, r.maxsum, l.maxrightsum + r.maxleftsum});
    return p;
}
void build(int node, int s, int e){
    if (s == e) {
        tree[node].sum = tree[node].maxleftsum = tree[node].maxrightsum = tree[node].maxsum = a[s];
        return;
    }
    int mid = s+e>>1;
    build(node<<1,s,mid);
    build(node<<1|1,mid+1,e);
    tree[node] = Merge(tree[node<<1],tree[node<<1|1]);
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
    Node result = Merge(left,right);
    return result;
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    build(1,0,n-1);
    scanf("%d",&w);
    for (i = 0; i < w; i++){
        scanf("%d%d",&t1,&t2);
        printf("%d\n",query(1,0,n-1,t1-1,t2-1).maxsum);
    }
}
