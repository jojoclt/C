#include <bits/stdc++.h>
using namespace std;
int n,k,i,j,c,cnt,ans;
int a,b,val;
struct node{
    int x,y;
};
struct pipe{
    node a,b;
    int val;
    bool operator < (pipe a) const{
        return a.val > val;
    }
};
struct value{
    node a;
    int val;
    bool operator < (value a) const{
        return a.val > val;
    }
};
map <node,int> connect;
vector <node> v;
//vector <pipe> q;
map <node,value> m;
priority_queue <pipe> pq;
int main(){
    scanf("%d%d",&n,&k);
    cnt = n;
    for (i = 0; i < n; i++){
        scanf("%d%d",&a,&b);
        v.push_back({a,b});
    }
    for (i = 0; i < n; i++){
        k = 0;
        for (j = i+1; j < n; j++){
            c = abs(v[i].x-v[j].x)+abs(v[i].y-v[j].y);
            m[v[i]] = {v[j],c};
        }
    }
    pq.push(m[v[0]].x,m[v[0]].y,m[v[1]]);
    while (!pq.empty()){
        pipe t = pq.top(); pq.pop();
        if (connect[t.b])continue;
        connect[t.b] = 1;
        printf("%d\n",t.val);
        ans += t.val;
        pq.push({t.b})
//        node t = v.top(); v.pop();
//        if (connect[v.top()]) continue;
//        connect[v.top()] = 1;
//        c = abs(t.x-v.top().x) + abs(t.y-v.top().y);
//        p.push({v.top().x,v.top().y,c})
//        printf("%d\n",c);
    }
    printf("%d",ans);
}
