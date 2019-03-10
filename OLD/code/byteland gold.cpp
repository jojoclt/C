#include <bits/stdc++.h>
using namespace std;
int n,tmp,high = 0;
int f(int n){
    if (n == 0) return 0;
    else{
        tmp = f(n/2) + f(n/3) + f(n/4);
        if (tmp > n) high = tmp;
        else high = n;
        }
}
int main(){
    while(scanf("%d",&n)){
        f(n);
        printf("%d\n",high);
    }
}
