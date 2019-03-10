#include <iostream>
#include <climits>
using namespace std;

int i,n,k,t;
long long ans = LLONG_MIN,val;
int a[1000005];
long long sum[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = 0ll + sum[i-1] + a[i];
	}
	for (i = 1; i <= n-k+1; i++){
		ans = max(ans,0ll + val + sum[i+k-1]-sum[i-1]);
		val += 0ll + a[i];
		if (val < 0) val = 0;
	}
	cout << ans;
}