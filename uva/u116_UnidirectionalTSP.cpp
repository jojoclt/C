#include <bits/stdc++.h>
using namespace std;

int m,n;
int i,j,ans = 1e9,t,c;
int a[11][101];
int mem[11][101];
int track[11][101];
void check(){
    printf("\n\n\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            printf("%d ",mem[i][j]);
        printf("\n");
    }
}
int f(int x, int y){
    if (y == n) return 0;
    if (mem[x][y]) return mem[x][y];
    mem[x][y] = 1e9;
    int to;
    for (int i = -1; i <= 1; i++){
        to = (x+i+m)%m;
        c = f(to,y+1) + a[x][y];
        if (mem[x][y] > c){
            mem[x][y] = c;
            track[x][y] = to;
        }
        else if (mem[x][y] == c && track[x][y] > to){
           track[x][y] = to;            
        }
    }
    // printf("mem[%d][%d] = %d\n",x,y,mem[x][y]);
    return mem[x][y];
}
int main(){
    while (scanf("%d%d",&m,&n) != EOF && m && n){
        ans = 1e9;
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                mem[i][j] = track[i][j] = 0;
                scanf("%d",&a[i][j]);
            }
        }
        
        for (i = 0; i < m; i++){
            if (ans > f(i,0)){
                ans = f(i,0);
                t = i;
            }
        }
        
        printf("%d",t+1);
        for (j = 0; j < n-1; j++){
            printf(" %d",track[t][j]+1);
            t = track[t][j];
        }
        //check();
        printf("\n%d\n",ans);
    }
}