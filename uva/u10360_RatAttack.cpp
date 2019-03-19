#include <bits/stdc++.h>
using namespace std;
int T,d,n;
int i,j,k,t1,t2,t3;
int mx,my,x,y,high = -1;
int killed[1025][1025];
void Clear(){
    fill(&killed[0][0],&killed[1024][1024],0);
    mx = my = x = y = high = -1;
}
bool check(int x, int y){
    if (x >= 0 && x <= 1024 && y >= 0 && y <= 1024) return 1;
    return 0;
}
int main(){
    scanf("%d",&T);
    while (T--){
        Clear();
        scanf("%d%d",&d,&n);
        for (i = 0; i < n; i++){
            scanf("%d%d%d",&t1,&t2,&t3);
            mx = max(mx,t1); my = max(my,t2);
            for (j = t1-d; j <= t1+d; j++){
                for (k = t2-d; k <= t2+d; k++){
                    if (check(j,k)) killed[j][k] += t3;
                }
            }
        }

        for (i = 0; i <= mx; i++){
            for (j = 0; j <= my; j++){
                if (killed[i][j] > high){
                    high = killed[i][j];
                    x = i, y = j;
                }
            }
        }
        printf("%d %d %d\n",x,y,high);
    }
}