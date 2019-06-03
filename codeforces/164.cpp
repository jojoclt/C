#include <iostream>
using namespace std;
using ll = long long;
int n;
int i;
ll a[123456];
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
        a[i] += a[i-1];
    }
    for (i = 2; i <)
}