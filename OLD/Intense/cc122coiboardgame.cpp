#include <bits/stdc++.h>
using namespace std;
char a[500][500];
int mem[505][505][2][2][2];
int i,j,n,m,Ei,Ej,ni,nj;
int cx[] = {-1,1,0,0};
int cy[] = {0,0,-1,1};
struct node{
    int x,y,j,b,p;
};
bool check(int x, int y){
    if (x >= 0 && x < n && y >= 0 && y < m) return 1;
    return 0;
}

queue <node> q;
int main(){
    scanf("%d%d",&n,&m);
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf(" %c",&a[i][j]);
            if (a[i][j] == 'S'){
                q.push({i,j,0,0,0});
            }
            else if (a[i][j] == 'E'){
                Ei = i;
                Ej = j;
            }
        }
    }
    while(!q.empty()){
        node t = q.front(); q.pop();
        if (t.x == Ei && t.y == Ej){
            printf("%d",mem[t.x][t.y][t.j][t.b][t.p]);
            return 0;
        }
        for (i = 0; i < 4; i++){
            ni = t.x+cx[i];
            nj = t.y+cy[i];
            if (check(ni,nj) && !mem[ni][nj][t.j][t.b][t.p]){
                if (a[ni][nj] == 'j' || a[ni][nj] == 'b' || a[ni][nj] == 'p'){
                    if (a[ni][nj] == 'j' && !t.j){//if needed to make ally
                        mem[ni][nj][1][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
                        q.push({ni,nj,1,t.b,t.p});
                    }
                    else if (a[ni][nj] == 'b' && !t.b){
                        mem[ni][nj][t.j][1][t.p] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
                        q.push({ni,nj,t.j,1,t.p});
                    }
                    else if (a[ni][nj] == 'p' && !t.p){
                        mem[ni][nj][t.j][t.b][1] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
                        q.push({ni,nj,t.j,t.b,1});
                    }
                    else{//if already ally
                        mem[ni][nj][t.j][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
                        q.push({ni,nj,t.j,t.b,t.p});
                    }
                }
                else if ((a[ni][nj] == 'J' && t.j)||(a[ni][nj] == 'B' && t.b)||(a[ni][nj] == 'P' && t.p)||
                a[ni][nj] == 'S' || a[ni][nj] == 'E' || a[ni][nj] == '.'){
                    mem[ni][nj][t.j][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
                    q.push({ni,nj,t.j,t.b,t.p});
                }

            }
        }
       //printf("mem[%d][%d][%d][%d][%d] = %d\n",ni,nj,t.j,t.b,t.p,mem[ni][nj][t.j][t.b][t.p]);
    }
    printf("-1");
    return 0;
}
/*
2 5
S.J.b
.jB.E

7

*/
