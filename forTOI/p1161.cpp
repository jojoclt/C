#include <bits/stdc++.h>
using namespace std; //> 0 -v 1 -< 2 -^ 3
struct node{
    int x,y;
};
bool check(int a, int b){

}
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int a,b,i,j,k;
char c;
int path[105][105][4],w[105][105];
queue <node> q;
int main(){
    cin >> a >> b;
    for (i = 1; i <= a; i++){
        for (j = 1; j <= b; j++){
            scanf(" %c",&c);
            if (c == 'N') {
                for (k = 0; k < 4; k++) path[i][j][k] = -1;
                path[i-1][j][1] = -1;
                path[i][j-1][0] = -1;
                path[i+1][j][3] = -1;
                path[i][j+1][2] = -1;
            }
            else if (c == 'B') {
                for (k = 0; k < 4; k++) path[i][j][k] = (path[i][j][k]<0)? -1:1;
                path[i-1][j][1] = (path[i-1][j][1]<0)? -1:1;
                path[i][j-1][0] = (path[i][j-1][0]<0)? -1:1;
                path[i+1][j][3] = (path[i-1][j][3]<0)? -1:1;
                path[i][j+1][2] = (path[i][j+1][2]<0)? -1:1;
            }
            else if (c == 'R') {
                path[i][j][0] = (path[i][j][0]<0)? -1:1;
                path[i][j+1][2] = (path[i][j+1][2]<0)? -1:1;
            }
            else if (c == 'D') {
                path[i][j][1] = (path[i][j][1]<0)? -1:1;
                path[i+1][j][3] = (path[i-1][j][3]<0)? -1:1;
            }
        }
    }
    w[1][1] = 1;
    q.push({1,1});
    while (!q.empty()){
        node t = q.front(); q.pop();
        for (i = 0; i < 4; i++){
            int tx = t.x+x[i], ty = t.y+y[i];
            if (path[t.x][t.y][i] == 1 && !w[tx][ty]){
                w[tx][ty] = w[t.x][t.y] + 1;
                q.push({tx,ty});
            }
            else if (path[t.x][t.y][i] == 1 && w[tx][ty]){
                if (w[t.x][t.y] + 1 == w[tx][ty]){
                    cout << w[tx][ty] <<endl;
                    cout << tx << " " << ty<<endl;
                    return 0;
                    while(!q.empty())q.pop();

                }
            }
        }
    }
    for (i = 1; i <= a; i++){
        for (j = 1; j <= b; j++) cout << w[i][j] << " ";
        cout<<endl;
    }
}
