#include <bits/stdc++.h>
using namespace std;
int n,k,i,w[100],v[100],result;
long long mem[100][10000];

long long f(int i, int c){
    if (mem[i][c]) return mem[i][c];
    if (i == n || c == 0) mem[i][c] = 0;
    else if (w[i] > c)
        mem[i][c] = f(i+1,c);
    else{
        mem[i][c] = max(f(i+1,c),v[i] + f(i+1,c-w[i]));
    }
    return mem[i][c];
}

int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++)
        scanf("%d%d",&w[i],&v[i]);
    printf("%d",f(0,k));
}
