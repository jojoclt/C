#include <bits/stdc++.h>
using namespace std;
int T = 2,i,j,k,t1,t2;
int m,n,E,hello;
int high;
int wall[505][505];
bool OK;
int fence(int x,int y,int s){
    int t1 = wall[x][y]-wall[x-s][y]-wall[x][y-s]+wall[x-s][y-s];
    x--,y--,s-=2;
    int t2 = wall[x][y]-wall[x-s][y]-wall[x][y-s]+wall[x-s][y-s];
    return t1-t2;
}
int main(){
    while (T--){
        fill(&wall[0][0],&wall[505][0],0);
        scanf("%d%d%d",&m,&n,&E);
        hello = min(m,n);
        OK = 0;
        for (i = 1; i <= E; i++){
            scanf("%d%d",&t1,&t2);
            wall[t1+1][t2+1] = 1;
        }
        for (i = 1; i <= m; i++){
            for (j = 1; j <= n; j++){
                wall[i][j] += wall[i-1][j]+wall[i][j-1]-wall[i-1][j-1];
            }
        }
        // for (i = 1; i <= m; i++){
        //     for (j = 1; j <= n; j++){
        //         printf("%d ",wall[i][j]);
        //     }
        //     printf("\n");
        // }
        // return 0;
        for (k = hello; k >= 1; k--){
            for (i = m; i >= k; i--){
                for (j = n; j >= k; j--){
                    if (!fence(i,j,k)){
                        printf("%d\n",k);
                        OK = true;
                        break;
                    }
                }
                if (OK) break;
            }
            if (OK) break;
        }
    }
}

/*
5 8
6
0 7
1 3
2 0
3 6
4 2
4 5
5 5
8
0 0
0 4
4 0
4 4
0 1
2 0
2 4
4 3
*/