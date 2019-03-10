#include<bits/stdc++.h>

using namespace std;
int n,k;
int i,a[100005],ans = 0;
int b[100005];
int x,high=0,low=1000000;

int main()
{
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        if(x > high) high = x;
        if(x < low) low = x;
        b[x]++;
    }
    while(high-low>k)
    {
        x = min(b[low],b[high]);
        b[high] -= x;
        b[high-1]+=x;
        b[low]-=x;
        b[low+1]+=x;
        if(b[high]==0) high--;
        if(b[low]==0) low++;
        ans+=x;
    }
    cout << ans;

}
