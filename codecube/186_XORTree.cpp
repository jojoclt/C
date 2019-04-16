#include <bits/stdc++.h>
using namespace std;
int V,E;
int i,t1,t2,t3;
struct axis{
	int x,val;
};
vector <axis> v[100005];
int mem[100005];
void fun(int x, int val, int last){
	mem[x] = val;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i].x == last) continue;
		fun(v[x][i].x,val^v[x][i].val,x); 
	}
	return ;
}
int main(){
	scanf("%d%d",&V,&E);
	for (i = 0; i < V-1; i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		v[t1].push_back({t2,t3});
		v[t2].push_back({t1,t3});
	}
	fun(1,0,1);
	for (i = 0; i < E; i++){
		scanf("%d%d",&t1,&t2);
		printf("%d\n",mem[t1]^mem[t2]);
	}
}