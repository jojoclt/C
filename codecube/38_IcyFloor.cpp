#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,w;
};
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int n,i,j,X,Y;
int wall[1005][1005],m[1005][1005][4];
queue <node> q;
bool check(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return 1;
	return 0;
}
int main(){
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> wall[i][j];

	q.push({0,0,0});
	q.push({0,0,1});
	while (!q.empty()){
		node t = q.front(); q.pop();
		if (t.x == n-1 && t.y == n-1){
			cout << m[t.x][t.y][t.w];
			return 0;
		}
		X = t.x+x[t.w], Y = t.y+y[t.w];
		if (check(X,Y) && !wall[X][Y] && !m[X][Y][t.w]){
			m[X][Y][t.w] = m[t.x][t.y][t.w] + 1;
			q.push({X,Y,t.w});
		}
		else{
			for (i = 0; i < 4; i++){
				X = t.x+x[i], Y = t.y+y[i];
				if (check(X,Y) && !wall[X][Y] && !m[X][Y][i]){
					m[X][Y][i] = m[t.x][t.y][t.w] + 1;
					q.push({X,Y,i});
				}
			}
		}
		//printf("m[%d][%d][%d] = %d\n",t.x,t.y,t.w,m[t.x][t.y][t.w]);
	}
}