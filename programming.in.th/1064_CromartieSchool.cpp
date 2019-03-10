#include <bits/stdc++.h>
using namespace std;
int m,n;
int S=0,P=1e9;
char c[66][66];
int a[66][66];
bool visit[66][66];
int i,j,k,T,minimum,X,Y,cnt;
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
struct node{
    int x,y;
}t,tc;
vector <node> v;
queue <node> q,Q;
void print(int x[][66]){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++) cout << x[i][j]<< " ";
        cout<<endl;
    }
}
bool check(int x, int y){
    if (x <= m && y <= n && c[x][y] == 'P') return 1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    minimum = min(m,n);
    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            scanf(" %c",&c[i][j]);
            if (c[i][j] == 'T') a[i][j] = 1;
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    for (k = minimum; k >= 1; k--){
        for (i = m; i >= k; i--){
            for (j = n; j >= k; j--){
                T = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
                if (T) continue;
                S = k;
                Q.push({i,j});
            }
        }
        if(S)break;
    }
   // for(i=0;i<)
    while(!Q.empty()){
        tc = Q.front(); Q.pop();
        cnt = 0;
        memset(visit,false,sizeof(visit));

        for (int ii = tc.x-S+1; ii <= tc.x; ii++){
            for (int jj = tc.y-S+1; jj <= tc.y; jj++){
                if (c[ii][jj] == 'P' && !visit[ii][jj]){
                    cnt++;
                    q.push({ii,jj});
                    while (!q.empty()){
                        t = q.front(); q.pop();
                        for (int z = 0; z < 4; z++){
                            X = t.x+x[z], Y = t.y+y[z];
                            if (check(X,Y) && !visit[X][Y]){
                                visit[X][Y] = true;
                                q.push({X,Y});
                            }
                        }
                    }
                }
            }
        }
        P = min(P,cnt);
    }
    if (S == 0 && P == 1e9){
        printf("0 0");
        return 0;
    }
    printf("%d %d\n",S*S,P);
}