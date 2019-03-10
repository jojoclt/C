#include <bits/stdc++.h>
using namespace std;
int m,n,sx,sy,ex,ey,ans=1e9,cnt;
int i,j,X,Y;
int tx[] = {0,1,0,-1};
int ty[] = {1,0,-1,0};
struct node{
	int x,y;
};
queue <node> q;
vector <node> v;
bool a[155][155];
int visit[155][155];
int mem[155][155];
void print(){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
            printf("%d ",mem[i][j]);
        printf("\n");
    }

}
void Clear(){
	while(!q.empty()) q.pop();
	memset(mem,0,sizeof(mem));
}


int main(){
	scanf("%d%d%d%d%d%d",&m,&n,&sx,&sy,&ex,&ey);
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			scanf("%d",&a[i][j]);

	q.push({sx,sy});
	while (!q.empty()){
		node t = q.front(); q.pop();
		for (i = 0; i < 4; i++){
			X = t.x+tx[i], Y = t.y+ty[i];
            if (a[X][Y] && !visit[X][Y]){
				visit[X][Y] = visit[t.x][t.y] + 1;
				q.push({X,Y});
			}
			else if (!a[X][Y] && !visit[X][Y]){
				visit[X][Y] = visit[t.x][t.y] + 1;
				v.push_back({X,Y});
			}
		}
	}

	for (j = 0; j < v.size(); j++){
        X = v[j].x, Y = v[j].y;
		q.push({X,Y});
		mem[X][Y] = visit[X][Y];

		while (!q.empty()){
			node t = q.front(); q.pop();
			if (t.x == ex && t.y == ey){
				ans = min(ans,mem[t.x][t.y]+1);
				cnt++;
				Clear();
			}
			else{
                for (i = 0; i < 4; i++){
                    X = t.x+tx[i], Y = t.y+ty[i];
                    if (a[X][Y] && !mem[X][Y] && !visit[X][Y]){
                        mem[X][Y] = mem[t.x][t.y] + 1;
                        q.push({X,Y});
                    }
                }
			}

		}
	}
	printf("%d\n%d\n",cnt,ans);
}

/*
5 8
4 5
2 8
0 0 1 1 0 0 0 0
1 0 1 1 0 1 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1

4
6

6 8
1 4
2 7
0 0 1 1 0 0 0 0
1 0 1 1 0 0 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1
0 1 0 1 1 1 1 1

4
13
*/
