#include <bits/stdc++.h>
using namespace std;
struct cube{
	int x,val;
	bool operator < (cube t) const{
		return val < t.val;
	}
};
priority_queue <int> q;
int n,m,k;
int i,j;
int a[105][10005];
int main(){
	cin >> n >> m >> k;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];

	for (i = 1; i < n; i++){
		priority_queue <cube> heap;
		for (j = 0; j <= k; j++){
			heap.push({j,a[i-1][j]});
		}
		for (j = 0; j < m; j++){
			if (j > 0 && j + k < m) heap.push({j+k,a[i-1][j+k]});
			while (heap.top().x < j-k) heap.pop();
			a[i][j] += heap.top().val;
			//printf("%d ",a[i][j]);
			if (i == n-1) q.push(a[i][j]);
		}
		//printf("\n");

	}
	cout<<q.top();

}