#include <bits/stdc++.h>
using namespace std;
int i,n,s[605],tmp;
int sum(int x, int y){
	return s[y] - s[x-1];
}
int mem[605][605];
int f(int x, int y){
	if (mem[x][y]) return mem[x][y];
	if (x == y) return 0;
	for (int i = x; i < y; i++)
		mem[x][y] = max(mem[x][y],(sum(x,i)<sum(i+1,y))?(2*sum(x,i)+sum(i+1,y)+f(x,i)+f(i+1,y)):(2*sum(i+1,y)+sum(x,i)+f(i+1,y)+f(x,i)));
	return mem[x][y];
}
int main(){
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		scanf("%d",&tmp);
		s[i]=s[i-1]+tmp;
	}
	printf("%d",f(1,n));
}

// 4
// 1 4 5 2