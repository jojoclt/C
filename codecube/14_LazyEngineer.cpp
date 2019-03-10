#include <bits/stdc++.h>
#define Print(x,a,b) for (int i = a; i <= b; i++) printf("mem[%d] = %d\n",i,x[i]);
using namespace std;
struct node{
	int x,val,isEven,i;
	bool operator < (node t) const{
		return val > t.val;
	}
}t;
struct vec{
    int x,val,i;
};
int m,n,mem[1005][2];
int i,t1,t2,t3;
int ans1=1e9,ans2;
vector <vec> v[1005];

priority_queue<node>pq;
int main(){
	scanf("%d%d",&m,&n);
	fill(&mem[0][0],&mem[1004][2],1e9);
	for (i = 1; i <= n; i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		v[t1].push_back({t2,t3,i});
        v[t2].push_back({t1,t3,i});
	}
	mem[1][1] = 0;
	pq.push({1,0,0,1});
	while(!pq.empty()){
		t = pq.top(); pq.pop();
		if (t.x == m && t.isEven%2 && t.val==mem[t.x][t.isEven%2] && t.i < ans1){
            ans1 = min(ans1,t.i);
            ans2 = t.val;
        }
        for (i = 0; i < v[t.x].size(); i++){
            int tx = v[t.x][i].x;
            int tval = t.val+v[t.x][i].val;
            int ti = max(t.i,v[t.x][i].i);
            int tisEven = (t.isEven+1)%2;
            if (tval <= mem[tx][tisEven]){
                mem[tx][tisEven] = tval;
                pq.push({tx,tval,tisEven,ti});
            }
        }
	}
    printf("%d %d",ans1,ans2);
} 