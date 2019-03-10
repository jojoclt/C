#include <bits/stdc++.h>
using namespace std;
int a[1000][1000],b[1000][1000];
int main(){
    int i,j,k;
    int x,y;
    int high = -1e9,tmp;
    scanf("%d%d",&x,&y);
    for (i = 1; i <= x; i++)
        for (j = 1; j <= y; j++)
            scanf("%d",&a[i][j]);

    for (i = 1; i <= x; i++)
        for (j = 1; j <= y; j++)
            a[i][j] += a[i][j-1];

    for (i = 1; i <= x; i++){
        for (j = i; j <= x; j++){
            tmp += a[i][j];
            for (k = 0; k < y; k++){
                tmp += a[k][j];
            }
        }
    }

    for (i = 1; i <= x; i++){
        for (j = 1; j <= y; j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
}
