#include <bits/stdc++.h>
using namespace std;
int i,n,mw,w[1000],v[1000],mem[1000][1000],ans = 0;

int f(int x, int c){
    if (x == n || c == 0) return 0;
    else if (w[x] > c) mem[x][c] = f(x+1,c);
    else{

        mem[x][c] = max(f(x+1,c),f(x+1,c-w[x])+v[x]);
    }
printf("mem[%d][%d]=%d,%d\n",x,c,f(x+1,c),f(x+1,c-w[x])+v[x]);
    return mem[x][c];

}

int main(){
    scanf("%d%d",&n,&mw);
    for (i = 0; i < n; i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    printf("%d",f(0,mw));
}
