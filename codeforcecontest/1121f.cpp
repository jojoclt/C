#include <bits/stdc++.h>
using namespace std;
int n,a,b,i;
int ans;
string s,t;
int f(int x, int y){
    if (mem[x][y]) return mem[x][y];
    for (int i = x; i < y; i++){
        t = s.substr(x,i-x+1);
        if (t == s.substr(s,i))
    }
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    cin >> s;
    f(0,n);
}
