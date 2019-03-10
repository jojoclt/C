#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct node{
    int x,val,time;
    bool operator < (node a)const{
        return a.val < val;
    }
};
vector <node> v[1000];
priority_queue <node> heap;
int a,b,t,k;
int c1,c2,val;
int x[1000];
int mem[1000];
int main(){
    int n,e,i;
    int pos1,pos2;
    scanf("%d%d",&n,&e);
    scanf("%d%d",&pos1,&pos2);

    for (i = 0; i < e; i++){
        scanf("%d%d%d",&c1,&c2,&val);
        v[c1].push_back({c2,val,inf});
    }
    scanf("%d%d%d%d",&a,&b,&t,&k);
    v[a].push_back({b,t,k});
    heap.push({pos1,0,0});
    fill(&mem[0],&mem[1000],inf);
    mem[pos1] = 0;
    while(!heap.empty()){
        node t = heap.top(); heap.pop();
        for (i = 0; i < v[t.x].size(); i++){
            if (t.time >= v[t.x][i].time && mem[v[t.x][i].x] > v[t.x][i].val + t.val){
                mem[v[t.x][i].x] = v[t.x][i].val + t.val;
                heap.push({v[t.x][i].x,mem[v[t.x][i].x],v[t.x][i].time});
            }
        }
    }
    printf("%d",mem[pos2]);
}
/*
4 4
0 3
1 3 -10 10
0 1 5
0 3 10
1 3 3
2 3 5

-5

*/
