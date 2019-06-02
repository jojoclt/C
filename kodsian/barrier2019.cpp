#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,k,i;
ll a[6000001];
struct node{ int x; ll val; };
deque<node>dq;
ll _max; int cnt;
int main(){
    scanf("%d%d",&n,&k);
    for (i = 1; i <= n; i++) scanf("%lld",&a[i]),a[i] += a[i-1];
    dq.push_front({1,0});
    for (i = 2; i <= n; i++){
        int tx;ll tval;
        while (i-dq.front().x >= k) dq.pop_front();
        while (!dq.empty() && dq.back().val >= a[i-1]) dq.pop_back();
        dq.push_back({i,a[i-1]});
        tx = i-dq.front().x+1, tval = a[i]-dq.front().val;
        if (_max < tval) _max = tval,cnt = tx;
        else if (_max == tval) cnt = min(cnt,tx);
    }
    printf("%lld\n%d",_max,cnt);
}