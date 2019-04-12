#include <bits/stdc++.h>
using namespace std;
int n,tree[100];
int i,t;
int sum(int a, int b){
    a += n; b += n;
    int s = 0;
    while (a <= b){
        if (a%2 == 1) s += tree[a++];
        if (b%2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void add(int k, int x){
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2)
        tree[k] = tree[2*k] + tree[2*k+1];
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        add(i,t);
    }
    int a = 3, b = 5;
    cout << sum(a,b);
}
/*
8
5 8 6 3 2 7 2 6

12
*/