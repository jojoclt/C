#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
struct node{
    int x,y;
    bool operator < (node t) const{
        return x < t.x || ((x == t.x) && (y < t.y));
    }
}arr[100005],t[100005];
double dist;
int i,t1,t2;
int q,n,r,d;
double euc(ll x, ll y){ return sqrt(x*x + y*y)-(2*r);}

double Merge(int l, int m, int r){
    double mid = arr[m].x;
    int i,j;
    for (i = m; i >= l; i--){
        if (euc(arr[i].x-mid,0) >= d) break;
        for (j = m+1; j <= r; j++){
            if (euc(arr[i].x-arr[j].x,0) >= d) break;
            dist = min(dist,euc(arr[i].x-arr[j].x,arr[i].y-arr[j].y));
        }
    }
    return dist;
}
double ClosestPair(int l, int r){
    if (l < r){
        if (l == r-1) return euc(arr[l].x-arr[r].x,arr[l].y-arr[r].y);
        int m = (l+r)>>1;
        dist = min(dist,ClosestPair(l,m));
        dist = min(dist,ClosestPair(m+1,r));
        dist = min(dist, Merge(l,m,r));
        return dist;
    }
    return inf;
}
int main(){
    scanf("%d",&q);
    while (q--){
        dist = inf;
        scanf("%d%d%d",&n,&r,&d);
        for (i = 0; i < n; i++) scanf("%d%d",&arr[i].x,&arr[i].y);
        sort(arr,arr+n);
        dist = min(dist,ClosestPair(0,n-1));
        // cout << dist;
        if (dist < d) printf("N\n");
        else printf("Y\n");
    }
}