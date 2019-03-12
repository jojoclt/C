#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z,from,visit,d;
}t,t1,t2;
int square(int x){ return x*x; };
int n,shop,low = 1e9;
int sx,sy,sz;
vector <node> v,item;
queue <node> q;
int M,K,C;
int i,j,ex,ey,ez,t11,t22,t33;
int dist[15][15];

int main(){
    scanf("%d",&n);
    scanf("%d%d%d",&sx,&sy,&sz);
    scanf("%d",&shop);
    v.push_back({sx,sy,sz,0,0,0});
    item.push_back({0,0,0,0,0,0});

    for (i = 0; i < shop; i++){
        scanf("%d%d%d",&ex,&ey,&ez);
        scanf("%d%d%d",&t11,&t22,&t33);
        v.push_back({ex,ey,ez,0,0,0});
        item.push_back({t11,t22,t33,0,0,0});
    }
    for (i = 0; i < v.size(); i++){
        for (j = i+1; j < v.size(); j++){
            t1 = v[i], t2 = v[j];
            t11 = square(t1.x-t2.x) + square(t1.y-t2.y) + square(t1.z-t2.z);
            dist[i][j] = dist[j][i] = t11;
        }
        
    }
    q.push({0,0,0,0,1<<0,0});
    while (!q.empty()){
        t = q.front(); q.pop();
        if (t.x >= n && t.y >= n && t.z >= n){
            low = min(low,t.d);
            continue;
        }
        for (i = 1; i <= shop; i++){
            if (1 << i & t.visit) continue;
            int xx = t.x+item[i].x;
            int yy = t.y+item[i].y;
            int zz = t.z+item[i].z;
            q.push({xx,yy,zz,i,1<<i|t.visit,t.d+dist[t.from][i]});
            // printf("x = %d y = %d z = %d ",xx,yy,zz);
            // printf("dist = %d\n",t.d+dist[t.from][i]);
        }
    }
    cout << low;
}

/*
1
0 0 0
2
10 0 0
2 5 7
0 10 0
0 3 9
*/