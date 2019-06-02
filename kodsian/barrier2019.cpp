#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{int x, l;};
int n,w,i,j;
ll a[6000005];
deque<node>dq;
ll _max,val;
int rng=1e9;
int main(){
    scanf("%d%d",&n,&w);
    for (i = 1; i <= n; i++) scanf("%lld",&a[i]),a[i] += a[i-1];
    for (i = 1, j = 1; i <= n; i++){
        while (!dq.empty() && a[i] <= a[dq.back().x]) dq.pop_back(),++j;
        dq.push_back({i,j});
        printf("%d ",dq.front().x);
    }
    
}