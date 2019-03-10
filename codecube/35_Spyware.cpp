#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[100005],mem[100005];
int i,t,t1,t2,high;
long long cnt;
bool visit[100005];
vector <int> v[100005];
unordered_map <int,vector<int>> w;
queue <int> q;
priority_queue <int> pq;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    for (i = 0; i < m; i++){
        scanf("%d%d",&t1,&t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    q.push(k);
    visit[k] = true;
    while (!q.empty()){
        t = q.front(); q.pop();
      //  if (visit[t]) continue;
        for (i = 0; i < v[t].size(); i++){
            t1 = v[t][i];
            if (visit[t1]) continue;
            visit[t1] = true;
            mem[t1] = mem[t]+1;
            w[mem[t1]].push_back(a[t1]);
            high = max(high,mem[t1]);
            q.push(t1);
        }
    }
//    for (i = 1; i <= n; i++) printf("mem[%d] = %d\n",i,mem[i]);
//    return 0;
    for (i = high; i > 0; i--){
        for (auto c : w[i]) pq.push(c);
        if (pq.top() < 0) continue;
        cnt += pq.top();
        pq.pop();
    }
    for (i = 1; i <= n; i++) if (!visit[i] && a[i] > 0) cnt += a[i];
    printf("%lld",cnt);
}
