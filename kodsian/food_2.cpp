#include <bits/stdc++.h>
using namespace std;
bool a[15];
int i,n,e,t;
int b[15];
int c;
void food(int x, int y){
    if (x == n){
        for (int k = 0; k < n; k++){
            printf("%d ",b[k]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++){
        if (x == 0 && y != i) continue;
        if (c & 1 << i) continue;
        c |= 1 << i;
        b[x] = i;
        food(x+1,y);
        c ^= 1 << i;
    }

}
int main(){
    scanf("%d%d",&n,&e);
    for (i = 0; i < e; i++) scanf("%d",&t),a[t] = true;
    for (i = 1; i <= n; i++) if (!a[i]) food(0,i);
}