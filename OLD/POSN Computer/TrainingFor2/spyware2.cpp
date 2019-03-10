#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long sum;
int a[100000];
vector<long long>v[100000];
priority_queue<long long>pq[100000];
priority_queue<long long>b;
int mem[100000];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int>q;
	q.push(k);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<v[t].size();i++){
			if(!mem[v[t][i]]&&v[t][i]!=k){
				mem[v[t][i]]=mem[t]+1;
				pq[mem[t]+1].push(a[v[t][i]-1]);
				q.push(v[t][i]);
			}
		}
	}
	int c=1;
	while(!pq[c].empty()){
		//printf("normal +%d\n",pq[c].top());
		if(pq[c].top()>0){
			sum+=pq[c].top();
			b.push(-pq[c].top());
		}
		else b.push(0);
		pq[c].pop();
		if(c>1){
		   while(!pq[c].empty()){
			   if(-pq[c].top()<b.top()){
					//printf("%d\n",b.top());
					sum+=b.top();
					b.pop();
					b.push(-pq[c].top());
					//printf("+%d\n",pq[c].top());
					sum+=pq[c].top();
			   }
			   pq[c].pop();
			}
		}
		c++;
	}
	for(int i=1;i<=n;i++){
		if(!mem[i]&&i!=k&&a[i-1]>0)
			sum+=a[i-1];
	}
	printf("%lld",sum);
	return 0;
}
/*
5 5 2
8 8 3 10 7
1 2
2 4
1 3
1 4
4 5

6 5 1
5 4 6 7 8 10
1 2
1 3
2 4
2 5
3 6

6 5 4
8 10 1 200 6 7
4 1
3 2
1 3
4 5
1 5

5 8 4
1 -10 -100 10 10
1 5
1 4
1 2
5 2
5 4
4 3
2 3
5 3
*/
