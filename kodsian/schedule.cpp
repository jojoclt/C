#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,val,day;
	bool operator < (node t) const{
		return day > t.day || (day == t.day) && val > t.val;
	}
}t;
int T,n;
int i,tt;
int a[1005][2];
priority_queue <node> pq;
void c(int a, int b, int c, int d){
	printf("t.x = %d t.y = %d val = %d day = %d\n",a,b,c,d);
}
bool visit[1005][1005];
int main(){
	scanf("%d%d",&T,&n);
	for (i = 1; i <= n; i++) scanf("%d",&a[i][0]);
	for (i = 1; i <= n; i++) scanf("%d",&a[i][1]);
	pq.push({0,0,0,1});
	while (!pq.empty()){
		t = pq.top(); pq.pop();
		// c(t.x,t.y,t.val,t.day);
		if (t.x == n && t.y == n){
			printf("%d\n%d",t.day,t.val);
			return 0;
		}
		if (visit[t.x][t.y]) continue;
		visit[t.x][t.y] = true;
		if (t.x < n){
			tt = t.val+a[t.x+1][0];
			if (tt > T) pq.push({t.x+1,t.y,a[t.x+1][0],t.day+1});
			else pq.push({t.x+1,t.y,tt,t.day});
		}
		if (t.y < n){
			tt = t.val+a[t.y+1][1];
			if (tt > T) pq.push({t.x,t.y+1,a[t.y+1][1],t.day+1});
			else pq.push({t.x,t.y+1,tt,t.day});
		}
	}
}