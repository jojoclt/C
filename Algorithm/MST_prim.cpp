#include <bits/stdc++.h>////PRIM
using namespace std;
struct node{
	int x,val;
	bool operator <(node t) const{
		return  t.val < val;
	}
}t;
int i,j,t1,t2,t3;
int n,k,cnt;
vector <node> v[200005];
bool visit[200005];
priority_queue <node> q;
int main(){
	scanf("%d%d",&n,&k);
	for (i = 0; i < k; i++){
		cin >> t1 >> t2 >> t3;
		v[t1].push_back({t2,t3});
		v[t2].push_back({t1,t3});
	}
	//for(i=0;i<v[0].size();i++) printf("v[0][%d] = %d\n",i,v[0][i]);
	q.push({0,0});
	while(!q.empty()){
		t = q.top(); q.pop();
		//if (visit[t.x]) continue;
		visit[t.x] = true;
		for (i = 0; i < v[t.x].size(); i++){
			if(!visit[v[t.x][i].x]) q.push({v[t.x][i].x,v[t.x][i].val});
		}
		cnt += t.val;
	}
	cout << cnt;
}
