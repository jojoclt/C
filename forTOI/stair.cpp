#include <bits/stdc++.h>
using namespace std;
int n;
long long mem[505][505];
long long stair(int prev, int remain){
    if (remain == 0) return 1;
    if (remain <= prev) return 0;
    if (mem[prev][remain] != -1) return mem[prev][remain];
    long long cnt = 0;
    for (int i = prev+1; i <= remain; i++) cnt += stair(i,remain-i);
    return mem[prev][remain] = cnt;
}
int main(){
    fill(&mem[0][0],&mem[505][0],-1);
    cin >> n;
    cout << stair(0,n)-1;
}
