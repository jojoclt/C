#include <bits/stdc++.h>
using namespace std;
int n;
int i;
string a,b,c;
bool mem[1005][1005],visit[1005][1005];
int al,bl;
bool f(int x, int y){
    if (x == al && y == bl) return 1;
    if (visit[x][y]) return mem[x][y];
    visit[x][y] = true;
    if (a[x] == c[x+y] && x < al) mem[x][y] |= f(x+1,y);
    if (b[y] == c[x+y] && y < bl) mem[x][y] |= f(x,y+1);
    return mem[x][y];
}
int main(){
    ios::sync_with_stdio(0);
    cin >> a >> b;
    al = a.length(); bl = b.length();
    cin >> n;
    for (i = 0; i < n; i++){
        memset(mem,0,sizeof(mem));
        memset(visit,0,sizeof(visit));
        cin >> c;
        if (f(0,0)) cout << "Yes\n";
        else cout << "No\n";
    }
}

/*
BAB
AB
4
BAABB
BABAB
ABBAB
BBABA
*/