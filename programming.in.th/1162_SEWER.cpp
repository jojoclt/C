#include <bits/stdc++.h>
using namespace std;
int i,j,a,b;
char c;
struct node {
    int x,y;
};
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int val[105][105];
int path[105][105][4];
queue <node> q;

int main(){
    val[1][1] = 1;
    cin >> a >> b;
    for (i = 1; i <= a; i++){
        for (j = 1; j <= b; j++){
            scanf(" %c",&c);
            if (c == 'B') path[i][j][0] = path[i][j][1] = path[i][j+1][2] = path[i+1][j][3] = 1;
            else if (c == 'D') path[i][j][1] = path[i+1][j][3] = 1;
            else if (c == 'R') path[i][j][0] = path[i][j+1][2] = 1;
        }
    }
    q.push({1,1});
    while (!q.empty()){
        node t = q.front(); q.pop();
        for (i = 0; i < 4; i++){
            int tx = t.x+x[i], ty = t.y+y[i];
            if (path[t.x][t.y][i] && !val[tx][ty]){
                val[tx][ty] = val[t.x][t.y] + 1;
                q.push({tx,ty});
            }
            else if (path[t.x][t.y][i] && val[tx][ty]){
                if (val[t.x][t.y] + 1 == val[tx][ty]){
                    cout << val[tx][ty] << endl;
                    cout << tx << " " << ty << endl;
                    return 0;
                }
            }
        }
    }
    for (i = 1; i <= a; i++){
        for (j = 1; j <= b; j++){
            cout << val[i][j] << " ";
        }
        cout<<endl;
    }
}