#include <bits/stdc++.h>
using namespace std;
string a,b;
int m,n,mem[205][205],i,j,result,row,col;
char c[205];
int main(){
    cin >> a >> b;
    m = a.length(); n = b.length();
    for (i = 0; i <= m; i++){
        for (j = 0; j <= n; j++){
            if (i == 0 || j == 0) 
                mem[i][j] = 0; 
            else if (a[i-1] == b[j-1]){
                mem[i][j] = mem[i-1][j-1]+1;
                if (result < mem[i][j]){
                    result = mem[i][j];
                    row = i;
                    col = j;
                }
            }
            else mem[i][j] = 0;
        }
    }
    while(mem[row][col]){
        c[--result] = a[row-1];
        row--;
        col--;
    }
    cout << c;
}