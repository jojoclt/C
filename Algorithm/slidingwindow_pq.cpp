#include <bits/stdc++.h>
using namespace std;
priority_queue <pair<int,int>> window;
int n,k,a[1005];
int i;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++){
        window.push(make_pair(-a[i],i));
        while (window.top().second <= i-k) window.pop();
        if (i >= k-1) cout << (-window.top().first) << ' ';
    }
}