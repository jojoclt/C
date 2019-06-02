//https://codeforces.com/problemset/problem/506/A
#include<bits/stdc++.h>
using namespace std;
int cnt[30003];
int mem[30003];
int n,s;
int i,j,t,_max;
int main(){
    scanf("%d%d",&n,&s);
    for (i = 0; i < n; i++){
        scanf("%d",&t), ++cnt[t];
        _max = max(_max,t);
    }
    mem[s] = cnt[s];
    for (i = s; i <= _max; i++){

    }
}