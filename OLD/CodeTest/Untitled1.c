#include <bits/stdc++.h>
using namespace std;

int n;

struct node{
    int x,y;
};
queue<node> q;
int cx[] = {-1,0,1,0};
int cy[] = {0,1,0,-1};

int mem[1000][1000];

bool check(int x, int y){
    if (x < 0 || y < 0 || x > n || y > n) return 0;
    return 1;
}

int main(){
    int sx,sy,i,j;
    scanf("%d",&n);
    scanf("%d%d",&sx,&sy);
    q.push({sx,sy});
    while (!q.empty()){
        node t = q.front(); q.pop();
        for (i = 0; i < 4; i++){
            if (check(t.x+cx[i],t.y+cy[i])){
                if (!mem[t.x+cx[i]][t.y+cy[i]]){
                    mem[t.x+cx[i]][t.y+cy[i]] = mem[t.x][t.y]+1;// XXX
                    q.push({t.x+cx[i],t.y+cy[i]});
                }
            }
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d ",(sx == i && sy == j)?0:mem[i][j]);
        }
        printf("\n");
    }
}
