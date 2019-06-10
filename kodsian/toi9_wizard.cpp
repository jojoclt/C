#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
    bool operator < (node t) const{
        return x < t.x || x == t.x && y < t.y;
    }
    bool operator == (node t) const{
        return x == t.x && y == t.y;
    }
};
struct Hash{
    size_t operator()(const node& p) const
    {
        return p.x ^ p.y;
    }
};
int n,i,j,t1,t2;
int x,y;
node a[4][1505];
unordered_map<node,node,Hash> m(10000000);
int main(){
    scanf("%d%d",&x,&y);
    scanf("%d",&n);
    for (i = 0; i < 4; i++){
        for (j = 0; j < n; j++){
            scanf("%d%d",&t1,&t2);
            a[i][j] = {t1,t2};
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            t1 = a[0][i].x + a[1][j].x;
            t2 = a[0][i].y + a[1][j].y;
            m[{t1,t2}] = {i,j};
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            t1 = x - (a[2][i].x + a[3][j].x);
            t2 = y - (a[2][i].y + a[3][j].y);
            auto it = m.find({t1,t2});
            if (it != m.end()){
                t1 = it->second.x;
                t2 = it->second.y;
                printf("%d %d\n",a[0][t1].x,a[0][t1].y);
                printf("%d %d\n",a[1][t2].x,a[1][t2].y);
                printf("%d %d\n",a[2][i].x,a[2][i].y);
                printf("%d %d\n",a[3][j].x,a[3][j].y);
            }
        }
    }

}
