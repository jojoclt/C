#include <bits/stdc++.h>
using namespace std;

int n,i,j,k;
int mem[1000][1000][4];
int ice[1000][1000];

int cx[] = {0,0,-1,1};
int cy[] = {-1,1,0,0};
struct ion{
    int x,y,d;
};

bool check(int x, int y){
    if (x >= 0 && x < n && y >= 0 && y < n) return 1;
    return 0;
}
queue <ion> q;

int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d",&ice[i][j]);
    q.push({0,0,1});
    q.push({0,0,3});
    while (!q.empty()){
        ion u = q.front();
        q.pop();
        if (u.x == n-1 && u.y == n-1){
            printf("%d",mem[u.x][u.y][u.d]);
            return 0;
        }
        if (check(u.x+cx[u.d],u.y+cy[u.d]) && ice[u.x+cx[u.d]][u.y+cy[u.d]] == 0 && !mem[u.x+cx[u.d]][u.y+cy[u.d]][u.d]){
                mem[u.x+cx[u.d]][u.y+cy[u.d]][u.d] = mem[u.x][u.y][u.d] + 1;
                q.push({u.x+cx[u.d],u.y+cy[u.d],u.d});
//                printf("a");
            }

        else{
            for (i = 0; i < 4; i++){
                if (check(u.x+cx[i],u.y+cy[i]) && ice[u.x+cx[i]][u.y+cy[i]] == 0 && !mem[u.x+cx[i]][u.y+cy[i]][i]){
                    mem[u.x+cx[i]][u.y+cy[i]][i] = mem[u.x][u.y][u.d] + 1;
                    q.push({u.x+cx[i],u.y+cy[i],i});
                }
            }
//            printf("b");
        }
//        printf("mem[%d][%d][%d] = %d\n",u.x,u.y,u.d,mem[u.x][u.y][u.d]);
        //printf(" check.%d ice.%d mem.%d\n",check(u.x+cx[u.d],u.y+cy[u.d]),ice[u.x+cx[u.d]][u.y+cy[u.d]],!mem[u.x+cx[u.d]][u.y+cy[u.d]][u.d]);
//    }

    }
//    for (k = 0 ;k < 4; k++){
//            for (i = 0; i < n; i++){
//                for (j = 0; j < n; j++){
//                    printf("%d ",mem[i][j][k]);
//                }
//                printf("\n");
//            }
//            printf("++++++++++++++++++++\n");
//        }
}
