#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,j,b,p;
};
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};
int m,n,mem[505][505][2][2][2];
char a[505][505];
int i,j,X,Y;
int ex,ey;
queue <node> q;
bool check(int x, int y){
	if (x >= 0 && y >= 0 && x < m && y < n) return 1;
	return 0;
}
int main(){
	cin >> m >> n;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			scanf(" %c",&a[i][j]);
			if (a[i][j] == 'S') q.push({i,j,0,0,0});
			else if (a[i][j] == 'E'){
				ex = i; ey = j;
			}
		}
	}
	while (!q.empty()){
		node t = q.front(); q.pop();
		if (t.x == ex && t.y == ey){
			cout << mem[t.x][t.y][t.j][t.b][t.p];
			return 0;
		}
		for (i = 0; i < 4; i++){
			X = t.x+x[i]; Y = t.y+y[i];
			if (check(X,Y) && !mem[X][Y][t.j][t.b][t.p] && a[X][Y] != '#'){
				if (a[X][Y] == 'J' && t.j || a[X][Y] == 'B' && t.b || a[X][Y] == 'P' && t.p ||
					a[X][Y] == '.' ||
					a[X][Y] == 'E' || a[X][Y] == 'S'){
					mem[X][Y][t.j][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
					q.push({X,Y,t.j,t.b,t.p});
				}
				else if (a[X][Y] == 'j' || a[X][Y] == 'b' || a[X][Y] == 'p'){
					if (a[X][Y] == 'j' && !t.j){
						mem[X][Y][1][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
						q.push({X,Y,1,t.b,t.p});
					}
					else if (a[X][Y] == 'b' && !t.b){
						mem[X][Y][t.j][1][t.p] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
						q.push({X,Y,t.j,1,t.p});
					}
					else if (a[X][Y] == 'p' && !t.p){
						mem[X][Y][t.j][t.b][1] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
						q.push({X,Y,t.j,t.b,1});
					}
					else{
						mem[X][Y][t.j][t.b][t.p] = mem[t.x][t.y][t.j][t.b][t.p] + 1;
						q.push({X,Y,t.j,t.b,t.p});
					}
				}
			}
		}
//		printf("mem[%d][%d][%d][%d][%d] = %d\n",t.x,t.y,t.j,t.b,t.p,mem[t.x][t.y][t.j][t.b][t.p]);
	}
	cout <<-1;
}