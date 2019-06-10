#include <bits/stdc++.h>
using namespace std;
int t;
int a[] = {6,8,4,2};
int main(){
    scanf("%d",&t);
    if (t == 0) cout << 1;
    else cout << a[t%4];
}