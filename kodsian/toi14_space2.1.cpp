#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
}t;
int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};
int a[1000][2001];
int b[1000][2001];
int m,n;
int i,j;
int st,diag,tri;
char c;
int main(){
    scanf("%d%d",&n,&m);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            scanf(" %c",&c);
            if (c == '1'){
                a[i][j] = a[i][j-1] +1;
                b[i][j] = b[i-1][j] +1;
            }
        }
    }

}