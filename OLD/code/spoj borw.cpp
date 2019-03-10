#include <bits/stdc++.h> //longest increasing subsequence
using namespace std;
int n,i,a[1000],mem[205][1000][1000];
int m1,m2,m3;
int lbw(int i, int w, int b){
    if (i == n) return 0;
    else{
        m1 = lbw(i+1,w,b);
        if (w > a[i]){
            printf("A%d %d\n",w,i);
            m2 = lbw(i+1,a[i],b) + 1;
        }
        if (b < a[i]){
            printf("B%d %d\n",b,i);
            m3 = lbw(i+1,w,a[i]) + 1;
        }
    }
    return max(m1,max(m2,m3));
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    printf("%d",lbw(0,-1,-1));//printf("%d",lis(0,0)); //becus test case has 0 so get impossible case.
}
