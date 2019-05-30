#include <bits/stdc++.h>
using namespace std;
struct node {
	int x,y;
};
int V,E,Q;
int i,t1,t2,t3,l,r,mid,t4;
int head[40005],v[50005][3];
vector <node> q;
int h(int x){
	if (head[x] == x) return x;
	return head[x] = h(head[x]);
}
bool noCopy(int x){
	for (i = 1; i <= V; i++){
		head[i] = i;
	}
	for (i = 0; i < E; i++){
		if (v[i][2] >= x) continue;
		head[h(v[i][0])] = h(v[i][1]);
	}
	for (i = 0; i < Q; i++){
		t3 = h(q[i].x), t4 = h(q[i].y);
		if (t3 == t4) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&V,&E,&Q);
	for (i = 0; i < E; i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		v[i][0] = t1;
		v[i][1] = t2;
		v[i][2] = t3;
	}
	for (i = 0; i < Q; i++){
		scanf("%d%d",&t1,&t2);
		q.push_back({t1,t2});
	}
	l = 1, r = 1e9;
	while (l <= r){
		mid = l + r >> 1;
		t1 = noCopy(mid), t2 = noCopy(mid+1);
		if (t1 && !t2){
			printf("%d",mid);
			return 0;
		} 
		else if(t1) l = mid+1;
		else r = mid-1;
	}
	printf("-1");
}