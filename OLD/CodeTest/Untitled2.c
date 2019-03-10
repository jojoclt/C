#include <bits/stdc++.h>
using namespace std;

struct state {
    int x, y, d, step;
};
int n;
int adj[][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

bool valid(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
        return true;
    }
    return false;
}

queue <state> q;
state u,v;
int ice[1000][1000];

int main(){
    int i,j;

    scanf("%d",&n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            scanf("%d",&ice[i][j]);
    }

    q.push({0,0,2,0});
    q.push({0,0,3,0});
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u.x == n-1 && u.y == n-1) {
            break;
        }
        v = u;
        v.x += adj[u.d][0];
        v.y += adj[u.d][1];
        v.step += 1;
        if (valid(v.x,v.y)) {
            if (ice[v.x][v.y] == 0) {
                q.push(v);
            }
            else {
                if (u.d%2 == 0) {
                    v = u;
                    v.d = 1;
                    v.x += adj[v.d][0];
                    v.y += adj[v.d][1];
                    v.step += 1;
                    if (valid(v.x,v.y)) {
                        if (ice[v.x][v.y] == 0) {
                            q.push(v);
                        }
                    }

                    v = u;
                    v.d = 3;
                    v.x += adj[v.d][0];
                    v.y += adj[v.d][1];
                    v.step += 1;
                    if (valid(v.x,v.y)) {
                        if (ice[v.x][v.y] == 0) {
                            q.push(v);
                        }
                    }
                }
                else {
                    v = u;
                    v.d = 0;
                    v.x += adj[v.d][0];
                    v.y += adj[v.d][1];
                    v.step += 1;
                    if (valid(v.x,v.y)) {
                        if (ice[v.x][v.y] == 0) {
                            q.push(v);
                        }
                    }

                    v = u;
                    v.d = 2;
                    v.x += adj[v.d][0];
                    v.y += adj[v.d][1];
                    v.step += 1;
                    if (valid(v.x,v.y)) {
                        if (ice[v.x][v.y] == 0) {
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
    printf("%d", u.step);
}
