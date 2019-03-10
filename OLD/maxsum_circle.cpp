#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e6+1;

int n, a[MAX];
ll sum[MAX], ans = LLONG_MIN;
deque<ll> dq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[n+i] = a[i];
	}
	dq.push_back(0);
	for(int i = 1; i <= 2*n; i++) {
		sum[i] = sum[i-1] + a[i];
		while(!dq.empty() && dq.front() < i - n) dq.pop_front();
		ans = max(sum[i] - sum[dq.front()], ans);
		while(!dq.empty() && sum[dq.back()] >= sum[i]) dq.pop_back();
		dq.push_back(i);
	}
	cout << ans;
}
