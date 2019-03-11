#include <bits/stdc++.h>
using namespace std;

int m,n;
int i,j,a[1005][1005],t1,t2,ans,cnt;
int track[1005][1005];
void check(int a[][1005]){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
            printf("%d ",a[i][j]);
        cout<<endl;
    }
}
int main(){
    scanf("%d%d",&m,&n);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            if (i == 1) track[1][j] = 1;
            scanf("%d",&a[i][j]);
            if (i%2==0){
                t1 = a[i-1][j]; t2 = a[i-1][j+1];
                if (t1 > t2) track[i][j] += track[i-1][j];
                else if (t1 < t2) track[i][j] += track[i-1][j+1];
                else track[i][j] += track[i-1][j] + track[i-1][j+1];
                a[i][j] += max(t1,t2);
            }
            else{
                t1 = a[i-1][j-1]; t2 = a[i-1][j];
                if (t1 > t2) track[i][j] += track[i-1][j-1];
                else if (t1 < t2) track[i][j] += track[i-1][j];
                else track[i][j] += track[i-1][j-1] + track[i-1][j];
                a[i][j] += max(t1,t2);
            }
        }
    }
    // check(track);
    // return 0;
    for (i = 1; i <= n; i++) ans = max(ans,a[m][i]);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            if (a[i][j] == ans) cnt += track[i][j];
        }
    }
    printf("%d %d",ans,cnt);
}