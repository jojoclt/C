#include<bits/stdc++.h>
using namespace std;
struct coor{
    int x,y,v;
};
queue<coor>pq;
vector<coor>a[100001];
int mem[1005][1005];
int n,m,c,d,ans;
int main(){
    scanf("%d%d%d%d",&n,&m,&c,&d);
        int x,y,v;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&v);
        a[x].push_back({x,y,v});
        a[y].push_back({y,x,v});
    }
    pq.push({0,c,0});
    while(!pq.empty()){
        int x=pq.front().x;
        int y=pq.front().y;
        int v=pq.front().v;
        if(y==d&&!ans){
            ans=mem[y][x];
        }
        pq.pop();
        for(int i=0;i<a[y].size();i++){
            if(!mem[a[y][i].y][y]&&a[y][i].y!=c){
                mem[a[y][i].y][y]=mem[y][x]+a[y][i].v;
                pq.push(a[y][i]);
            }
            else if(a[y][i].y==d){
                if(mem[y][x]+a[y][i].v<ans)ans=mem[y][x]+a[y][i].v;
            }
        }
    }
    printf("%d",ans);
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
