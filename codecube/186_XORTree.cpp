#include <bits/stdc++.h>
using namespace std;
struct axis{
	int x,y,val;
	bool operator < (axis t) const{
		return x < t.x || (x == t.x) && y < t.y;
	}
}t;
int V,E;
int i,t1,t2,t3;
vector <axis> v;
int mem[100005];
int main(){
	scanf("%d%d",&V,&E);
	for (i = 0; i < V-1; i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		v.push_back({t1,t2,t3});
	}
	sort(v.begin(),v.end());
	for (i = 0; i < V-1; i++){
		t = v[i];
		mem[t.y] = mem[t.x]^t.val;
		// mem[t.x] = mem[t.y]^t.val;
	}
	// for (i = 1; i <= V; i++) printf("%d\n",mem[i]);
	// return 0;
	for (i = 0; i < E; i++){
		scanf("%d%d",&t1,&t2);
		printf("%d\n",mem[t1]^mem[t2]);
	}
}