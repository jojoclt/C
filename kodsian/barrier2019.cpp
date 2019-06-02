#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,k,i;
ll a[6000005];
struct node{
    int x; ll val;
}t;
deque<node>dq;
int _max,cnt;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i <= n; i++) scanf("%lld",&a[i]),a[i] += a[i-1];
    for (i = 1; i <= n; i++){
        int tx,tval;
        while (!dq.empty() && i-dq.front().x >= k) dq.pop_front();
        while (!dq.empty() && dq.back().val >= a[i-1]) dq.pop_back();
        dq.push_back({i,a[i-1]});
        tval = a[i]-dq.front().val;
        if (_max < tval) _max = tval,cnt = i-dq.front().x+1;
        else if (_max == tval) cnt = min(cnt,i-dq.front().x+1);
    }
    printf("%lld\n%d",_max,cnt);
}