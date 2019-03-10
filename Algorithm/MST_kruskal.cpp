//////KRUSKAL
#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,val;
	bool operator <(node t) const{
		return  t.val < val;
	}
}t;
int i,j,t1,t2,t3,h[200005];
int n,k,cnt;
int head(int x){
	if (h[x] == x) return x;
	return h[x] = head(h[x]);
}
priority_queue <node> q;
int main(){
	scanf("%d%d",&n,&k);
	for (i = 0; i < k; i++){
		cin >> t1 >> t2 >> t3;
		q.push({t1,t2,t3});
	}
	for (i = 0; i < n; i++) h[i] = i;
	while(!q.empty()){
		t = q.top(); q.pop();
		if (head(t.x) != head(t.y)){
			h[head(t.x)] = head(t.y);
			printf("%d %d\n",t.x,t.y);
			cnt += t.val;
		}
	}
	cout << cnt;
}
