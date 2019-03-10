#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct node{
    int x,val;
    bool operator < (node a)const{
        return a.val < val;
    }
};
vector <node> v[1000];
priority_queue <node> heap;
int c1,c2,val;
int x[1000];
int mem[1000];
int main(){
    int n,e,i;
    int pos1,pos2;
    scanf("%d%d",&n,&e);

    for (i = 0; i < e; i++){
        scanf("%d%d%d",&c1,&c2,&val);
        v[c1].push_back({c2,val});
        v[c2].push_back({c1,val});
    }
    scanf("%d%d",&pos1,&pos2);
    heap.push({pos1,0});
    fill(&mem[0],&mem[1000],inf);
    while(!heap.empty()){
        node t = heap.top(); heap.pop();
        for (i = 0; i < v[t.x].size(); i++){
            if (mem[v[t.x][i].x] > v[t.x][i].val + t.val){
                mem[v[t.x][i].x] = v[t.x][i].val + t.val;
                heap.push({v[t.x][i].x,mem[v[t.x][i].x]});
            }
        }
    }
    printf("%d",mem[pos2]);
}
/*
5 6
1 2 3
2 4 5
4 5 6
2 3 2
1 3 1
3 5 2
1 5

3

*/
