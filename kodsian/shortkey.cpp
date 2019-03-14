#include <bits/stdc++.h>
using namespace std;
struct axis{
    int x,t;
};
int V,n,t,pos;
int i,j,t1,t2;
vector <int> v[200005];
int now[200005];
int main(){
    scanf("%d%d%d",&V,&n,&t);
    for (i = 0; i < n; i++){
        scanf("%d%d",&t1,&t2);
        v[t2].push_back(t1);
    }
    for (i = 1; i <= V; i++){
        now[i] = now[i-1]+1;
        for (j = 0; j < v[i].size(); j++)
            now[i] = min(now[i],now[v[i][j]]+1);
        if (now[i] <= t) pos = i;
    }
    printf("%d\n",now[V]);
    if (now[V] <= t) printf("1");
    else printf("0 %d",pos);
}