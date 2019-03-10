#include <bits/stdc++.h>
using namespace std;
long long n,tmp;
map<long long, long long> mem;

long long f(long long n){
    if (n == 0) mem[n] = 0;
    else if (mem[n]) return mem[n];
    else{
        tmp = f(n/2) + f(n/3) + f(n/4);
        if (tmp > n) mem[n] = tmp;
        else mem[n] = n;
        }
    return mem[n];
}
int main(){
    while(scanf("%lld",&n)){
        mem.clear();
        printf("%lld\n",f(n));
    }
}
