#include <bits/stdc++.h> //prim
using namespace std;
struct node{
    int x,y;
    bool operator <(node a)const
    {
        return a.y < y;
    }
};
int i,n,e,a,b,val,connect[1000],ans = 0;
vector<node> m[1000];
priority_queue<node>heap;
int main(){
    scanf("%d%d",&n,&e);
    for (i = 0; i < e; i++){
        scanf("%d%d%d",&a,&b,&val);
        m[a].push_back({b,val});
        m[b].push_back({a,val});
    }
    heap.push({1,0});
    while(!heap.empty()){
        node t = heap.top(); heap.pop();
        if(connect[t.x])continue;
        printf("%d\n",t.x);
        ans += t.y;
        connect[t.x] = 1;
        for (i = 0; i < m[t.x].size();i++){
            heap.push({m[t.x][i].x,m[t.x][i].y});
        }
    }
    printf("%d",ans);
}

/*

5 8
1 2 2
1 4 3
2 3 2
2 4 2
3 4 1
3 5 2
4 5 3
1 5 4

7

9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
6 7 2
6 8 6
2 8 2
2 5 4
2 3 7
3 5 14
3 4 9
4 5 10
5 6 2

38
*/
