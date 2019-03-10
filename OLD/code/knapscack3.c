#include <bits/stdc++.h>
using namespace std;
int n,k,i,w[100],v[100],result,mem[100];

long long f(int i, int c){
    if (i == n || c == 0) return 0;
    else if (w[i] > c){
        return f(i+1,c);
    }
    else{
        return max(f(i+1,c),v[i] + f(i+1,c-w[i]));
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++)
        scanf("%d%d",&w[i],&v[i]);
    printf("%d",f(0,k));
}
