#include <bits/stdc++.h>
using namespace std;
int main(){
    int i = 1,n,a[1000]= {},tmp,ans = -1e9;
    scanf("%d",&n);
    while (i <= n){
        scanf("%d",&tmp);
        a[i] = a[i-1]+tmp;
        if (a[i] < 0) a[i] = 0;
        i++;
    }
    for (i = 1; i <= n; i++)
        if (a[i] > ans){
            ans = a[i];
        }
    printf("%d",ans);
}
/*
9
1 -2 5 -8 3 5 -9 3 4

8
*/
