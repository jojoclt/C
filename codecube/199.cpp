#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int x,y,val,i;
    bool operator < (node t) const{
        return val > t.val;
    }
}t,tmp;
ll sum;
int V,E,T;
int i,t1,t2,t3;
vector <node> v;
int head[100005],rnk[100005];
bool visit[100005];

int c(int x){
    if (head[x] == x) return x;
    return head[x] = c(head[x]);
}
int main(){
    scanf("%d%d",&V,&E);
    for (i = 1; i <= V; i++) head[i] = i, rnk[i] = 1;
    for (i = 1; i <= E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v.push_back({t1,t2,t3,i});
    }
    scanf("%d",&T);
    sort(v.begin(),v.end());
    t3 = 0;
    for (i = 0; i < E; i++){
        t = v[i];
        t1 = c(t.x), t2 = c(t.y);
		if (t1 == t2){
			if (tmp.val < t.val) tmp = {t.x,t.y,t.val,t.i};
			continue;
		}
		if (rnk[t1] > rnk[t2]){
			head[t2] = t1;
			rnk[t1] += rnk[t2];
		}
		else{
			head[t1] = t2;
			rnk[t2] += rnk[t1];
		}
		visit[t.i] = true;
		sum += t.val;
		++t3;
    }
    if (t3 != V-1) {printf("-1"); return 0;}
    sum += tmp.val;
    visit[tmp.i] = true;
    printf("%lld\n",sum);
    if (T == 2) for (i = 1; i <= E; i++) if (visit[i]) printf("%d ",i);
}