#include <bits/stdc++.h>
using namespace std;
int n,i,x;
int a[1000000][2];
int mem[1001][1001] = {};

int main(){
    scanf("%d",&n);
    x = n;
    for (i = 0; i < n; i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
        mem[a[i][0]][a[i][1]]++;
    }
    for (i = 0; i < n ;i++){
        if (mem[a[i][0]][a[i][1]] > 1){
            x--;
            mem[a[i][0]][a[i][1]]--;
        }
    }
    printf("%d",x);
}
