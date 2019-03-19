#include<bits/stdc++.h>
using namespace std;
int n,k,i,j;
int p[5005],w[5005];
int mem[2][1880];
bool flag;
int main(){
    scanf("%d%d",&n,&k);
    k /= 8;
    for (i = 0; i < n; i++) scanf("%d",&p[i]);
    for (i = 0; i < n; i++) scanf("%d",&w[i]);
    mem[0][0] = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j <= k; j++){
           mem[flag][j] = mem[!flag][j];
           if (j >= w[i]) mem[flag][j] = max(mem[!flag][j],mem[!flag][j-w[i]]+p[i]);
        }
        flag = !flag;
    }
    cout <<mem[!flag][k];
}