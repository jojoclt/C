#include <bits/stdc++.h>
using namespace std;

int a[] = {1,2,2,2,3,4,4,5,6,6,6,7};
int n =12;
int main(){
    int l=0,r=n-1,mid,key=4;
    while (l < r){
        mid = l+r>>1;
        if (a[mid] >= key) r = mid;
        else l = mid+1;
    }
    cout << l;
}