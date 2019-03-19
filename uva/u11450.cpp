#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
int T,i,j;
int m,c,s[25],g[25][25];
int mem[205][25];
int wedding(int x, int y){
    if (x < 0) return -1e9;
    if (y == c) return m-x;
    if (mem[x][y] != -1) return mem[x][y];
    for (int i = 0; i < s[y]; i++){
        mem[x][y] = max(mem[x][y],wedding(x-g[y][i],y+1));
    }
    return mem[x][y];
}
int main(){
    scanf("%d",&T);
    while (T--){
        memset(mem,-1,sizeof(mem));
        scanf("%d%d",&m,&c);
        for (i = 0; i < c; i++){
            scanf("%d",&s[i]);
            for (j = 0; j < s[i]; j++) scanf("%d",&g[i][j]);
        }
        int c = wedding(m,0);
        if (c >= 0) printf("%d\n",c);
        else printf("no solution\n");
=======
int T;
int main(){
    scanf("%d",&T);
    while (T--){
        
>>>>>>> 47bab24e380e89bfd4aef58cc12549101566838e
    }
}