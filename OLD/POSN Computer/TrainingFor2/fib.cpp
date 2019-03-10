#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n==1||n==2)return 1;
    else return fib(n-1)+fib(n-2);
}
main(){
    int n;
    scanf("%d",&n);
    printf("%d",fib(n));\
    return 0;
}
