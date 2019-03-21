#include <bits/stdc++.h>
using namespace std;
int n,k;
int i;
int gen(int i, bool prev_zero){
    if (i == n) return 1;
    else{
        int c = (k-1)*gen(i+1,0);
        if (!prev_zero) c += gen(i+1,1);
        return c;
    }
}
int main(){
    cin >> n >> k;
    cout << gen(0,1);
}
