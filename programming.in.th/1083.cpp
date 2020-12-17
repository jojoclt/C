#include <iostream>
using namespace std;
int a[1000005],i,t1,t2,tmp,n;
int main(){
    scanf("%d",&n);
    scanf("%d",&t1);
    for (i = 2; i <= n ;i++){
        scanf("%d",&t2);
        tmp = (t2 > t1) ? t2 - t1 : 0;
        a[i] = a[i-1] + tmp;
        t1 = t2;
    }
    // for (i = 1; i <= n; i++) printf("%d ",a[i]);
    scanf("%d",&i);
    while (i--) scanf("%d%d",&t1,&t2), printf("%d\n",a[t2]-a[t1]);
}