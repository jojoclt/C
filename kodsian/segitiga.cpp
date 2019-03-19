#include <bits/stdc++.h>
using namespace std;
int T = 20;
int n,mem[256][256];
string s;
int segi(int x, int y){
    if (mem[x][y]) return mem[x][y];
    for (int i = x; i < y; i++){
        int l = segi(x,i), r = segi(i+1,y);
        if (mem[x][y] == 7) return mem[x][y];
        if (l & 1){
            if (r & 1) mem[x][y] |= 4;
            if (r & 2) mem[x][y] |= 2;
            if (r & 4) mem[x][y] |= 1;
        }
        if (l & 2){
            if (r & 1) mem[x][y] |= 4;
            if (r & 2) mem[x][y] |= 2;
            if (r & 4) mem[x][y] |= 2;
        }
        if (l & 4){
            if (r & 1) mem[x][y] |= 2;
            if (r & 2) mem[x][y] |= 4;
            if (r & 4) mem[x][y] |= 2;
        }
        
    }
    return mem[x][y];
}
int main(){
    while (T--){
        memset(mem,0,sizeof(mem));
        scanf("%d",&n);
        cin >> s;
        for (int i = 0; i < n; i++){
            if (s[i] == '0') mem[i][i] = 1;
            else if (s[i] == '1') mem[i][i] = 2;
            else if (s[i] == '2') mem[i][i] = 4;
        }
        if (segi(0,n-1) & 1) cout << "yes\n";
        else cout << "no\n";
    }
}