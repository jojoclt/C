#include <bits/stdc++.h>
using namespace std;
int n,t1,t2,pos,l,r,mid;
int i,a[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> t1;
        if (t1 > a[pos]) a[++pos]=t1;
        else{
            l = 0; r = pos;
            while (l <= r){
                mid = l+r>>1;
                if (a[mid] >= t1){
                    t2 = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
            a[t2] = t1;
        }
    }
    cout << pos;
}
