#include <bits/stdc++.h>
using namespace std;
int n,i,pos,t,c;
int l,r,mid;
int a[1000005];
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        if (t >= a[pos]) a[++pos] = t;
        else{
            l = 0; r = pos;
            while (l <= r){
                mid = l+r>>1;
                if (a[mid] > t){
                    c = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }
            a[c] = t;
        }
    }
    cout << n-pos;
}