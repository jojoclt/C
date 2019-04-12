#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int i;
int a[60000005];
struct Node{
    ll sum, prefixsum, suffixsum, maxsum;
    Node(){
        prefixsum = suffixsum = maxsum = LLONG_MIN;
        sum = 0;
    }
};
int n,w;
int main(){
    scanf("%d%d",&n,&w);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    // build(1,0,n-1);
}
