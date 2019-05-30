#include <bits/stdc++.h>
using namespace std;
int n,k;
int T[200001],P[200001];
int b[200001];
void kmpPreprocess(){
	int i = 0, j = -1; b[0] = -1;
	while (i < k) {
		while (j >= 0 && P[i] != P[j]){
			if (P[i] == 1) break;
			j = b[j];
		}
		i++, j++;
		if (P[i] == 1) b[i] = i-1;
		else b[i] = j;  
	}
}
int kmpSearch(){
	int i = 0, j = 0,cnt = 0;;
	while (i < n) {
		// printf("%d %d\n",i,j);
		while (j >= 0 && T[i] != P[j]){
			if (P[j] == 1) break;
			j = b[j];
		}
		i++, j++;
		if (j == k){
			++cnt;
			if (P[j-1] == 1) j -= 2;
			else j = b[j];
		}
	}
	return cnt;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; i++) scanf("%d",&T[i]);
	for (int i = 0; i < k; i++) scanf("%d",&P[i]);
	kmpPreprocess();
	// for (int i = 0; i < k; i++) printf("%d ",b[i]);
	cout << kmpSearch();
}