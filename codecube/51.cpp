#include <bits/stdc++.h>
#define inf 1e9
#define KK 5
using namespace std;
int V,E,K;
int i,j,k,t1,t2,t3,t4;
int c[17];
int dist[201][201];
int mem[16][1<<16];
int _min = inf;

int calc(int x, int y){
    if (y == (1 << K+1)-1) return dist[c[x]][V];
    if (mem[x][y]) return mem[x][y];
    mem[x][y] = inf;
    for (int i = 0; i <= K; i++){
        if (y & 1 << i) continue;
        mem[x][y] = min(mem[x][y],dist[c[x]][c[i]] + calc(i,y|1<<i));
    }
    return mem[x][y];
}
int main(){
    scanf("%d%d%d",&V,&E,&K);
    fill(&dist[0][0],&dist[V+1][0],inf);
    for (i = 1; i <= V; i++) dist[i][i] = 0;

    for (i = 1; i <= K; i++) scanf("%d",&c[i]); c[0] = 1;
    for (i = 0; i < E; i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        dist[t1][t2] = dist[t2][t1] = t3;
    }
    for (k = 1; k <= V; k++){
        for (i = 1; i <= V; i++){
            for (j = 1; j <= V; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("%d",calc(0,0));
    
}