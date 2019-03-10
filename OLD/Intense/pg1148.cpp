#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n,m,k,a[20000],c[20000],i,mem[20000][20000];
//int f(int x,int y){//x sushi y person
//    if (mem[x][y]) return mem[x][y];
//    if (x == m+1 && y == k) return 0;
//    else if (x == m+1 || y == k) return -inf;
//    else{
//        mem[x][y] = max(f(x+1,y),f(x+1,y+1))+(a[x+1]-a[x])*c[y];
//    }
//    return mem[x][y];
//}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    a[0] = 0;
    for (i = 1; i <= m; i++){
        scanf("%d",&a[i]);
    }
    a[m+1] = n;
    for (i = 0; i < k; i++){
        scanf("%d",&c[i]);
    }
//    printf("%d",f(0,0));
    for (int x = 0; x < m+2; x++){
        for (int y = 0; y < k; y++){
            if (x )
            mem[x][y] = max(mem[x-1][y-1],mem[x-1][y])+(a[x]-a[x-1])*c[y];
        }
    }
    printf("%d",mem[][]);
}
/*
10 5 3
1 3 5 8 9
4 2 2

36
*/
