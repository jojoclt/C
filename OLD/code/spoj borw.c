#include <bits/stdc++.h> // Longest Palindrome Subsequence
using namespace std;
char a[100];
//string a,b;
int mem[1005][1005],n;
int f(int i, int j){
    if(i==n || j==-1)return 0;
    else if(mem[i][j]==0)
    {
        if (a[i] == a[j]){
            mem[i][j] = max(mem[i][j],f(i+1,j-1)+1);
        }else{
        mem[i][j] = max(mem[i][j],f(i+1,j));
        mem[i][j] = max(mem[i][j],f(i,j-1));
        }
    }
    return mem[i][j];
}
int main(){
    scanf("%d%d",&n);
    scanf("%s",a);
    printf("%d",f(0,n-1));
}
