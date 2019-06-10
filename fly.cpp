#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,d;
}t,a[2005][2];
queue <node> q;
int m,n;
int D = -1;
int i,t1,t2; char c1,c2;
int main(){
    scanf("%d%d",&m,&n);
    for (i = 1; i < n; i++) q.push({0,i,0});
    for (i = 0; i < m; i++){
        scanf("%d %c%d %c",&t1,&c1,&t2,&c2);
        a[i][0].x = t1;
        a[i][0].y = c1 == 'R' ? 1 : -1;
        a[i][1].x = t2;
        a[i][1].y = c1 == 'R' ? 1 : -1;
    }
    a[m+1][0] = {-555,0}, a[m+1][1] = {555,0};
    while (!q.empty()){
        // cout <<"X";
        t = q.front(); q.pop();
        int x = t.x+1, y = t.y;
        if (x == m+1){
            printf("%d",t.d);
            return 0;
        }
        if (D != t.d){
            for (i = 0; i < m; i++){
                a[i][0].x += a[i][0].y;
                a[i][1].x += a[i][1].y;
                if (a[i][0].x > a[i][1].x) swap(a[i][0],a[i][1]);
                else{
                    if (a[i][0].x == -1) a[i][0] = {1,1};
                    if (a[i][1].x == n+1) a[i][1] = {n-1,-1};
                }
            }
            D = t.d;
        }
        if (a[x][0].x < y && y < a[x][1].x) q.push({x,y,t.d+1});
        q.push({t.x,y,t.d+1});
    }
}