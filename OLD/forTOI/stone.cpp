#include <bits/stdc++.h>
using namespace std;
int i,n,s,a[25];

int mindiff(int i, int val){
    if (i == n) return abs(2*val-s);
    else return min(mindiff(i+1,val),mindiff(i+1,val+a[i]));
}

int main(){
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    mindiff(0,0);

}
