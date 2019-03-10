#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, t1, t2, mem[901][8101];
int num(int s1, int s2)
{
	if (!s1 && !s2)
		return 0;
	//if (s1 < 0 || s2 < 0)
	//	return INF;
	if (s1 > 900 || s2 > 8100)
		return INF;
	if (mem[s1][s2] != -1)
		return mem[s1][s2];

	int cnt = INF;
	for (int i = 1; i <= 9; i++)
	{
		if(s1>=i && s2 >=i*i)
			cnt = min(cnt, 1+num(s1-i,s2-i*i));

	}
	return mem[s1][s2] = cnt;
}

void print(int s1, int s2)
{
	if (!s1 && !s2)
		return;
	if (s1 < 0 || s2 < 0)
		return;
	for (int i = 1; i <= 9; i++)
	{
		if (num(s1, s2) == 1 + num(s1 - i, s2 - (i * i)))
		{
			cout << i;
			print(s1 - i, s2 - (i * i));
			return;
		}
	}
}

int main()
{
	memset(mem, -1, sizeof(mem));
	cin >> n;
	while (n--)
	{
		cin >> t1 >> t2;
		int x = num(t1, t2);
	//	cout << x << endl;
		if (x == INF || x > 100)
			cout << "No solution\n";
		else
		{
			print(t1, t2);
			cout << endl;
		}
		// for (int i = 0; i <= t1;i ++){
		// 	for (int j = 0; j <= t2;j++){
		// 		printf("%d ",mem[i][j]);
		// 	}cout<<endl;
		// }
	}
}