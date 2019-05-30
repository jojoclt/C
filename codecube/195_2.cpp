#include <bits/stdc++.h>
using namespace std;
const int N = 700000;
int tree[N+5];
int a[N+5];
unordered_map <int,int> v;
int m,n;
int i,t;
void update(int k){
	for (; k <= m; k += k&-k) --tree[k];
}
int sum(int k){
	int s = 0;
	for (; k > 0; k -= k&-k) s += tree[k];
	return s;
}
int query(int k){
	int l = 1, r = m, mid;
	while (l < r){
		mid = (l+r)>>1;
		if (sum(mid) >= k) r = mid;
		else l = mid+1;
	}
	return l;
}
int main(){
	scanf("%d%d",&m,&n);
	for (i = 1; i <= m; i++) scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    for (i = 1; i <= m; i++){
        tree[i] = a[i]&-a[i];
        v[i] = a[i];
        update(i);
    }	
	for (i = 0; i < n; i++){
		scanf("%d",&t);
		t = query(t);
		printf("%d ",t);
	}
}