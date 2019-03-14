#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,val;
    bool operator < (node t) const{
        return val < t.val;
    }
}t;
int V,E;
int i,t1,t2,t3,ans;
bool visit[200005];
vector <node> v[200005];
priority_queue <node> q;
int main(){
    scanf("%d%d",&V,&E);
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        v[t1].push_back({t2,t3-1});
        v[t2].push_back({t1,t3-1});
    }
    q.push({1,0});
    while (!q.empty()){
        t = q.top(); q.pop();
        if (visit[t.x]) continue;
        visit[t.x] = true;
        for (i = 0; i < v[t.x].size(); i++){
            if (!visit[v[t.x][i].x])q.push({v[t.x][i].x,v[t.x][i].val});
        }
        // cout << t.val << endl;
        ans += t.val;
    }
    printf("%d",ans);
}

/*
6 9
1 2 8
2 3 6
1 4 6
4 2 6
4 5 8
2 5 7
5 6 5
2 6 9
3 6 5
*/