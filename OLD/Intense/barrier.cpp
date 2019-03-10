#include <bits/stdc++.h>
using namespace std;
int n,w,i,a[6000005];

struct house{
    int x,val;
};
deque <house> dq;
int main(){
    scanf("%d%d",&n,&w);
    for (i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    for(i = 1; i <=n; i++)printf("%d ",a[i]);

}
