#include <bits/stdc++.h>
using namespace std;
int t,n,i,tmp,cnt;
int a1,a2;
int main(){
    scanf("%d",&t);
    while (t--){
        cnt = a1 = a2 = 0;
        scanf("%d",&n);
        for (i = 0; i < n; i++){
            scanf("%d",&tmp);
            if (tmp%3==0) ++cnt;
            else if (tmp%3==1) ++a1;
            else ++a2;
        }
        int d = min(a1,a2);
        cnt += d;
        a1 -= d, a2 -= d;
        cnt += max(a1,a2)/3;
        printf("%d\n",cnt);
    }
}