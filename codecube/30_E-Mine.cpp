#include <iostream>
using namespace std;
// int mem[505][505][11], a[505][505];
int mem[2][505][55];
int t;
int n,val;
int i,j,k,ans;
bool c = 1;
// int f(int x, int y, int z){
// //	cout << x << " " << y << " " << z <<endl;
// 	if (x == n+1 || y ==n+1) return 0;
// 	if (mem[x][y][z]) return mem[x][y][z];
// 	mem[x][y][z] = max(mem[x][y][z],f(x,y+1,0));
// 	mem[x][y][z] = max(mem[x][y][z],f(x+1,y,0));
// 	if(z<val) mem[x][y][z] = max(mem[x][y][z],max(f(x+1,y,z+1),f(x,y+1,z+1))+a[x][y]);
// 	return mem[x][y][z];
// }
int main(){
	// x = flag na weii
////	cout << f(1,0,0);

	scanf("%d%d",&n,&val);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
            scanf("%d",&t);
			for (k = 0; k <= val; k++){
                if (k) mem[c][j][k] = max(mem[c][j][k], max(mem[!c][j][k-1],mem[c][j-1][k-1]) + t);
                mem[c][j][k] = max(mem[c][j][k], max(mem[!c][j][val],mem[c][j-1][val]));
			}
		}
		c = !c;
	}
	for (i = 0; i <= val; i++) ans = max(ans,mem[!c][n][i]);
	printf("%d",ans);
}

/*
5 2
1 1 3 2 1
1 1 2 9 1
1 1 1 9 1
1 1 1 1 9
1 1 1 1 1

32
*/
