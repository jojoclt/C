#include <bits/stdc++.h>
using namespace std;
int n,i,a[3005],cnt;
int mem[1005][3005];
int choc(int x,int y){
    if (mem[x][y]) return mem[x][y];
    if (x == n) return 0;
    if (y > 3000) return mem[x][y] = 1e9;
    else{
        mem[x][y] = choc(x+1,y+1) + 1;
        if (a[x] > y) mem[x][y] = min(mem[x][y],choc(x+1,a[x]));
    }
    return mem[x][y];
}
int main(){
    scanf("%d",&n);
    //fill(&mem[0][0],&mem[1005][0],1);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    printf("%d",choc(0,0));
}
/*
6
3 1 5 5 10 9

3



7
5 2 4 4 5 7 7

3

*/
