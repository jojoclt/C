#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+1;
struct coor{
    int y,v,s;
    bool operator <(coor a)const{
        return a.v<v;
    }
};
priority_queue<coor>pq;
vector<coor>a[MAXN];
int mem[MAXN];
int n,m,s,e,h,j,k,l;
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&e);
        int x,y,v;
    scanf("%d%d%d%d",&h,&j,&k,&l);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&v);
        a[x].push_back({y,v});
    }
    for(int i=0;i<n;i++)mem[i]=1e9;
    mem[s]=0;
    pq.push({s,0,0});
    while(!pq.empty()){
        coor t=pq.top();
        pq.pop();
        if(t.x==e)
        {
            printf("%d",mem[e]);
            break;
        }
        if(t.y==h&&mem[j]>k+t.v&&t.v<=l&&!t.s){
            mem[j]=k+t.v;
            pq.push({j,mem[j],1});
        }
        for(int i=0;i<a[t.y].size();i++){
            if(mem[a[t.y][i].y]>a[t.y][i].v+t.v){
                mem[a[t.y][i].y]=a[t.y][i].v+t.v;
                pq.push({a[t.y][i].y,mem[a[t.y][i].y],t.s});
            }
        }
    }
    printf("%d",mem[e]);
    return 0;
}
/*
4 4
0 3
1 3 -10 10
0 1 5
0 3 10
1 3 3
2 3 5
*/
