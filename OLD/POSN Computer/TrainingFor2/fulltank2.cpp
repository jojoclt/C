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
int n,m,t[1000],s[1000],e[1000];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
        int x,y,v;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&v);
        a[x].push_back({y,v});
        a[y].push_back({x,v});
    }
    int k;
    scanf("%d",&k);
    for(int f=0;f<k;f++){
        scanf("%d%d%d",&t[f],&s[f],&e[f]);
    }
    for(int f=0;f<k;f++){
        for(int i=1;i<=n;i++)for(int j=0;j<=t[f];j++)mem[i][j]=1e9;
        mem[s[f]][0]=0;
        pq.push({s[f],0,0});
        int par=0;
        while(!pq.empty()){
            road g=pq.top();
            pq.pop();
            if(g.y==e[f]){
                printf("%d\n",mem[e[f]][g.t]);

                par++;
                break;
            }
            int u=g.p;
            for(int i=g.t;i<=t[f];i++){
                for(int j=0;j<a[g.y].size();j++){
                    if(mem[a[g.y][j].y][i-a[g.y][j].v]>u&&a[g.y][j].v<=i){
                            //printf("from %d to %d i=%d >= a[g.y][j]=%d",g.y,a[g.y][j],i,a[g.y][j].y);
                        mem[a[g.y][j].y][i-a[g.y][j].v]=u;
                        //printf(" u=%d\n",u);
                        pq.push({a[g.y][j].y,mem[a[g.y][j].y][i-a[g.y][j].v],i-a[g.y][j].v});
                    }
                }
                u+=p[g.y];
            }

        }
        if(!par)printf("impossible\n");
    }

}
/*
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
2
10 0 3
20 1 4
*/
