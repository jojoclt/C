#include <bits/stdc++.h>
using namespace std;

int n,e,mem[1005];
struct node{
    int x,val;
    bool operator < (node a) const{
        return a.val < val;
    }
};
vector <node> v[1005];
priority_queue <node> heap;
int main(){
    int i,c1,c2,c3,last;
    scanf("%d%d",&n,&e);
    fill(&mem[2],&mem[n+1],1e9); // set infinite mem[start] = 0;
    for (i = 0; i < e; i++){
        scanf("%d%d%d",&c1,&c2,&c3);
        v[c1].push_back({c2,c3});
//        v[c2].push_back({c1,c3});
    }
    scanf("%d",&last);
    heap.push({1,0});
    while (!heap.empty()){
        node t = heap.top(); heap.pop();
        for (i = 0; i < v[t.x].size(); i++){
            if (t.val+v[t.x][i].val < mem[v[t.x][i].x]){
                mem[v[t.x][i].x] = t.val+v[t.x][i].val;
                heap.push({v[t.x][i].x,mem[v[t.x][i].x]});
                printf("mem[%d] = %d\n",v[t.x][i].x,mem[v[t.x][i].x]);
            }
        }
//        printf("mem[%d] = %d\n",t.x,mem[t.x]);
    }
    printf("%d",mem[last]);
}
/*
6 9
1 2 2
2 4 4
5 4 3
2 3 1
1 3 4
3 5 3
2 5 2
4 6 2
5 6 2
6

5 9
1 2 2
1 3 4
2 3 1
2 4 4
2 5 2
3 5 3
4 5 3
4 6 2
5 6 2
http://www.myassignmenthelp.net/images/dijkstra-shortest-path-algorithm-output.png
*/
