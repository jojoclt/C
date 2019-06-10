#include <bits/stdc++.h>
using namespace std;
int m,n,a;
long long sum = 1;
int main(){
    scanf("%d%d%d",&m,&n,&a);
    sum *= 1ll*((m+a-1)/a)*((n+a-1)/a);
    cout << sum;
}