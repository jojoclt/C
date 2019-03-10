#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,l,r;
};
int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
int i,j,X,Y,cnt;

char T;
int m,n,sx,sy,ll,rr;
bool a[2005][2005];
unordered_map <int,unordered_map<int,unordered_map<int,unordered_map<int,bool>>>> visit;
queue <node> q;
int main(){
    scanf("%d%d%d%d%d%d",&m,&n,&sx,&sy,&ll,&rr);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            scanf(" %c",&T);
            if (T == '.') a[i][j] = true;
        }
    }
    q.push({sx,sy,ll,rr});
    visit[sx][sy][ll][rr] = true;
    while(!q.empty()){
        node t = q.front(); q.pop();
        for (i = 0; i < 4; i++){
            X = t.x+x[i], Y = t.y+y[i];
            if (a[X][Y] && !visit[X][Y][ll][rr]){
                if (i == 0){
                    if (!t.r) continue;
//                    printf("X = %d Y = %d L = %d R = %d-1 i = %d\n",X,Y,t.l,t.r,i);
                    visit[X][Y][ll][rr] = true;
                    q.push({X,Y,t.l,t.r-1});
                    cnt++;
                }
                else if (i == 1){
                    if (!t.l) continue;
//                    printf("X = %d Y = %d L = %d-1 R = %d i = %d\n",X,Y,t.l,t.r,i);
                    visit[X][Y][ll][rr] = true;
                    q.push({X,Y,t.l-1,t.r});
                    cnt++;
                }
                else if (i == 2 || i == 3){
//                    printf("X = %d Y = %d L = %d R = %d i = %d\n",X,Y,t.l,t.r,i);
                    visit[X][Y][ll][rr] = true;
                    q.push({X,Y,t.l,t.r});
                    cnt++;
                }
            }
        }
    }
//    for (i = 1; i <= m; i++){
//        for (j = 1;j <= n; j++)
//            printf("%d ",visit[i][j]);
//        printf("\n");
//
//    }
    printf("%d",cnt+1);
}
