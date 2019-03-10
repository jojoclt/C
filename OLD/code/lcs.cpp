#include <bits/stdc++.h> // Longest Common Subsequence
using namespace std;
char a[100],b[100];
//string a,b;
int mem[1005][1005],n,m;
int f(int i, int j){
    if(i==n || j==m)return 0;
    else if(mem[i][j]==0)
    {
        if (a[i] == b[j]){
            mem[i][j] = max(mem[i][j],f(i+1,j+1)+1);
        }else{
        mem[i][j] = max(mem[i][j],f(i+1,j));
        mem[i][j] = max(mem[i][j],f(i,j+1));
        }
    }
    return mem[i][j];
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s%s",a,b);
    printf("%d",f(0,0));
}
