#include<bits/stdc++.h>
using namespace std;
int ans,n,c,d;
int main(){
    d=-1e9;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        c = c + x;
        if (d < c)
            d = c;

        if (c < 0)
            c = 0;
    }
    printf("%d",d);
    return 0;
}
