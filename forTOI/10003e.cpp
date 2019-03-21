#include <bits/stdc++.h>
using namespace std;

int A[55],l,n;
int i,m[55][55];
int c(int left, int right){
	if (left+1 == right) return 0;
	if (m[left][right] != -1) return m[left][right];
	int val = 2e9;
	for (int i = left+1; i < right; i++){
		val = min(val,c(left,i) + c(i,right) + (A[right]-A[left]));
	}
	return m[left][right] = val;
}
int main(){
	while (scanf("%d",&l), l){
		scanf("%d",&n);
		A[0] = 0;
		for (i = 1; i <= n; i++) scanf("%d",&A[i]);
		A[n+1] = l;
		memset(m,-1,sizeof(m));
		printf("The minimum cutting is %d.\n",c(0,n+1));
	}
}
