#include <iostream>
using namespace std;
int n,k,m=1e9;
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> k;
    m = min(k-1,n-k);
    cout << 4*m+3*(n-m-1)+3;
}