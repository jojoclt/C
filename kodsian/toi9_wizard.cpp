#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    bool operator < (node t) const{
        return x < t.x || (x == t.x) && y < t.y;
    }
    bool operator == (node t) const{
        return x == t.x && y == t.y;
    }
};
struct Hash{
    size_t operator()(const node& p) const
    {
        return (1+p.x) ^ p.y;
    }
};
int n,i,j,t1,t2;
int x,y;
node a[1500][4];
unordered_map<node,node,Hash> m1,m2;
int main(){
    scanf("%d%d",&x,&y);
    scanf("%d",&n);
    for (i = 0; i < 4; i++){
        for (j = 0; j < n; j++){
            scanf("%d%d",&t1,&t2);
            a[j][i] = {t1,t2};
        }
    }
//    m1.insert({{1,2},{3,4}});
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            m1[{a[i][0].x+a[j][1].x,a[i][0].y+a[j][1].y}] = {i,j};
            m2[{a[i][2].x+a[j][3].x,a[i][2].y+a[j][3].y}] = {i,j};
        }
    }
    for (auto c : m1) {
        if (m2.find({x-c.first.x,y-c.first.y}) != m2.end()){
            node x1 = m1[c.first], x2 = m2[{x-c.first.x,y-c.first.y}];
            printf("%d %d\n",a[x1.x][0].x,a[x1.x][0].y);
            printf("%d %d\n",a[x1.y][1].x,a[x1.y][1].y);
            printf("%d %d\n",a[x2.x][2].x,a[x2.x][2].y);
            printf("%d %d\n",a[x2.y][3].x,a[x2.y][3].y);
            return 0;
        }
    }

}
