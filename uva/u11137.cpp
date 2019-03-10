#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int i,j,c = 1;
ll coin[22],mem[10005],n;
ll N;
int main(){
    for (i = 1; i <= 21; i++) coin[i] = i*i*i;
    mem[0] = 1;
    for (i = 1; i <= 21; i++){
        for (j = coin[i]; j < 10000; j++){
            mem[j] += mem[j-coin[i]];
        }
    }
    while (scanf("%d",&n) != EOF){
        printf("%lld\n",mem[n]);
    }
    
}