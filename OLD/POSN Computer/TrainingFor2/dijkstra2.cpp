#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+1;
struct coor{
    int y,v;
    bool operator <(coor a)const{
        return a.v<v;
    }
};
priority_queue<coor>pq;
vector<coor>a[MAXN];
int mem[MAXN];
int n,m,s,e;
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&e);
        int x,y,v;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&v);
        a[x].push_back({y,v});
        a[y].push_back({x,v});
    }
    for(int i=1;i<=n;i++)mem[i]=1e9;
    mem[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        coor t=pq.top();
        pq.pop();
        for(int i=0;i<a[t.y].size();i++){
            if(mem[a[t.y][i].y]>a[t.y][i].v+t.v){
                mem[a[t.y][i].y]=a[t.y][i].v+t.v;
                pq.push({a[t.y][i].y,mem[a[t.y][i].y]});
            }
        }
    }
    printf("%d",mem[e]);
    return 0;
}
/*
9 11 1 5
1 2 1
2 3 4
3 6 3
3 4 2
3 5 6
4 5 7
3 9 5
6 4 2
5 9 2
6 8 4
6 7 1

5 6 1 5
1 2 3
2 4 5
4 5 6
2 3 2
1 3 1
3 5 2
*/
