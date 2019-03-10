#include<bits/stdc++.h>
using namespace std;
int n,c,d,e,f,g;
int a[1005],b[1005];
int main(){
    scanf("%d",&n);
    d=-1e9;
    f=-1e9;
    for(int i=0;i<n;i++){
            int x,y;
        scanf("%d",&x);
        y=-x;
        c = c + x;
        if (d < c)
            d = c;

        if (c < 0)
            c = 0;
        e = e + y;
        if (f < e)
            f = e;

        if (e < 0)
            e = 0;
        g+=x;
    }
    printf("%d",max(d,g+f));
    return 0;
}
/*
5
1 -101 99 -120 99
*/
