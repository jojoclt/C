#include <bits/stdc++.h>
using namespace std;
int m,n,i,j,t;
int mem[1005][1005];
bool value[1005][1005];
int x,y;
int main(){
	scanf("%d%d",&m,&n);
	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			scanf("%d",&t);
			if (!t) value[i][j] = true;
		}
	}
	mem[1][0] = 1;
	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			if (value[i][j]){
				mem[i][j] = (mem[i-1][j]+mem[i][j-1])%1000000007;
			}
		}
	}
//	for (i = 1; i <= m; i++){
//		for (j = 1; j <= n; j++){
//			printf("%d ",mem[i][j]);
//		}cout<<endl;
//	}
//	cout<<mem[m][n];
	printf("%d",mem[m][n]);
}