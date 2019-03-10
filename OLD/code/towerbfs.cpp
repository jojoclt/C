#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int k,m,n,i,j,a,b,d = -1,tmp,ans = 1;

vector <int> v[10001];
int mem[100001];

int main(){
    scanf("%d%d%d",&k,&n,&m);
    for (i = 1; i <= m ; i++){
        scanf("%d%d",&a,&b);
        v[b].push_back(a);
    }
    fill(&mem[0],&mem[100000],inf);

    mem[1] = 0;
    for (i = 1; i <= n; i++){
        tmp = inf;
        if (!v[i].size())continue;
        for (j = 0; j < v[i].size(); j++){
            tmp = min(tmp,mem[v[i][j]]);
        }
        mem[i] = tmp+1;
        if(mem[i]<=k)ans = i;
        //printf("mem[%d] = %d\n",i,mem[i]);

    }
    printf("%d",ans);
}
