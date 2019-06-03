#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string p = "QAQ";
int mem[4][105];
int main(){
    cin >> s;
    n = s.length();
    for(int j = 0; j <= n; j++) mem[0][j] = 1;
    for(int i = 1; i <= 3; i++){
        for (int j = 1; j <= n; j++){
            if (p[i-1] != s[j-1]) mem[i][j] = mem[i][j-1];
            else mem[i][j] = mem[i][j-1] + mem[i-1][j-1];
        }
    }
    printf("%d",mem[3][n]);
}