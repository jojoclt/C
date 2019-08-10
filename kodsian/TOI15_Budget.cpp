/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: LINUX
*/
/*
TASK: budget.cpp
LANG: C++
AUTHOR: Chalanthorn C
CENTER: SSWB
*/
#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,val,ok;
    bool operator < (node t) const{
        return ok > t.ok || ok == t.ok && val < t.val;
    }
};
struct prc{
    int x,y;
    bool operator < (prc t) const{
        return x < t.x;
    }
}p[500005];
const int N = 500005;
int V,E,i,q;
int t1,t2,t3,t4;
vector <node> v(500005);
long long sum;
int head[N],rnk[N];
int low[N];
int f(int x){
    if (head[x] == x) return x;
    return head[x] = f(head[x]);
}
int fun(int x){
    int l = 0, r = q-1, mid;
    while (l <= r){
        mid = (l+r)>>1;
        if (p[mid].x >= x) r = mid-1;
        else l = mid+1;
    }
    return low[l];
}
int main(){
    scanf("%d%d",&V,&E);
    for (i = 0; i < V; i++) head[i] = i,rnk[i] = 1;
    for (i = 0; i < E; i++){
        scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
        v.push_back({t1,t2,t3,t4});
    }

    sort(v.begin(),v.end());
    scanf("%d",&q);
    for (i = 0; i < q; i++){
        scanf("%d%d",&t1,&t2);
        p[i] = {t1,t2};
    }
    sort(p,p+q);
    low[q-1] = p[q-1].y;
    for (i = q-2; i >= 0; i--){
        low[i] = min(p[i].y,low[i+1]);
    }
    for (auto c : v){
        t1 = f(c.x), t2 = f(c.y);
        if (t1 == t2) continue;
        if (rnk[t1] > rnk[t2]){
            rnk[t1] += rnk[t2];
            head[t2] = t1;
        }
        else{
            rnk[t2] += rnk[t1];
            head[t1] = t2;
        }
        if (c.ok) continue;
        int pr = fun(c.val);
//        printf("t %d %d %dX%d\n",t1,t2,c.val,pr);
        sum += pr;
    }
    printf("%lld",sum);
}
