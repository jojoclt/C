#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int p,m,k,a[20000],i,coin,c;
int mem[1000005],trace[1000005];

int main(){
    scanf("%d%d%d",&p,&m,&k);
    for (i = 0; i < k; i++)
        scanf("%d",&a[i]);
    for (i = 1; i <= m; i++){
        mem[i] = inf;
        for (j = 0; j < k; j++){
            if (a[j] > i) continue; //if i-a[j] < 0 4-5 = -1 cannot be change
            c = mem[i-a[j]]+1;
            mem[i] = min(mem[i],c);
            if (mem[i] == c) trace[i] = j;
        }
    }

    for (i = m; i <= p; i++)
}
