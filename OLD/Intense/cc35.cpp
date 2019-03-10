#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,c1,c2,t,ans;
long long a[100005];
priority_queue <long long> h;
queue <int> q;
vector<int> v[100005];
int mem[100005];
int main(){
    fill(&mem[0],&mem[100005],-1);
    scanf("%d%d%d",&n,&m,&k);
    for (i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for (i = 1; i <= m; i++){
        scanf("%d%d",&c1,&c2);
        v[c1].push_back(c2);
        v[c2].push_back(c1);
    }
    q.push(k);
    mem[k] = 0;
    while (!q.empty()){
        t = q.front(); q.pop();
        for (i = 0; i < v[t].size(); i++){
            if (mem[v[t][i]] == -1){
                mem[v[t][i]] = mem[t] + 1;
                q.push(v[t][i]);
                printf("%d %d\n",v[t][i],mem[v[t][i]]);
            }
        }
        if (t == k) mem[t] = -1;
    }
     for(i = 1; i <= n; i++) if (mem[i]==-1 && a[i] > 0) ans+=a[i]; //not connect to virus. safe to pick
}
/*
5 5 2
5 8 2 10 7
1 2
2 4
1 3
1 4
4 5
*/
