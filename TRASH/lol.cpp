#include <bits/stdc++.h>
using namespace std;
int n,i,t;
vector <int> v;
void search(int x){
    // printf("%d",*upper_bound(v.begin(),v.end(),x));
    int l=0,r=n-1,mid;
    while (l <= r){
        mid = l+(r-l) / 2;
        
        if (v[mid] <= x) l =mid+1;
        else r = mid-1;
    }
    printf("%d\n",v[l]);
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    while (scanf("%d",&t),t){
        search(t);
    }
}