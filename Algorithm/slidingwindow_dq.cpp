#include <bits/stdc++.h>
using namespace std;
deque <int> dq;
int n,k,a[1005];
int i;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < k; i++){
        while (!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    for ( ; i < n; i++){
        cout << a[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i-k) dq.pop_front();
        while (!dq.empty() && a[i] >= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << a[dq.front()];
}