#include <bits/stdc++.h>
using namespace std;
int n,k,i,w1[100],w2[100],high;

long long f(int i, int c){
    if (i == k) return c;
    else if (w1[i] > c){
        f(i+1,c);
    }
    else{
        high = max(f(i+1,c),f(i+1,c-w2[i]));
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++)
        scanf("%d%d",&w1[i],&w2[i]);
    f(0,0);
    printf("%d",high);
}
