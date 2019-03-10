#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+1;
struct road{
    int y,p,t;
    bool operator <(road a)const{
        return a.p<p;
    }
};
struct coor{
    int y,v;
};
priority_queue<road>pq;
vector<coor>a[MAXN];
int mem[MAXN][101];
int p[1000];
int n,m,t,s,e;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
        int x,y,v;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&v);
        a[x].push_back({y,v});
        a[y].push_back({x,v});
    }
    scanf("%d%d%d",&t,&s,&e);
    for(int i=1;i<=n;i++)for(int j=0;j<=t;j++)mem[i][j]=1e9;
    mem[s][0]=0;
    pq.push({s,0,0});
    while(!pq.empty()){
        road g=pq.top();
        pq.pop();
        if(g.y==e){
            printf("%d",mem[e][g.t]);
            return 0;
        }
        int u=g.p;
        for(int i=g.t;i<=t;i++){
            for(int j=0;j<a[g.y].size();j++){
                if(mem[a[g.y][j].y][i-a[g.y][j].v]>u&&a[g.y][j].v<=i){
                        printf("from %d to %d i=%d >= a[g.y][j]=%d",g.y,a[g.y][j],i,a[g.y][j].y);
                    mem[a[g.y][j].y][i-a[g.y][j].v]=u;
                    printf(" u=%d\n",u);
                    pq.push({a[g.y][j].y,mem[a[g.y][j].y][i-a[g.y][j].v],i-a[g.y][j].v});
                }
            }
            u+=p[g.y];
        }

    }
    printf("-99");
    return 0;
}
/*
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
*/
