#include <iostream>
using namespace std;
int n,k,p;
int i;
int a[100105],mem[100005][105];
int fun(int x, int val){
    if (x >= n || val == k) return 0;
    if (mem[x][val]) return mem[x][val];
    mem[x][val] = fun(x+1,val);
    for (int i = 0; i < p; i++){
        mem[x][val] = max(mem[x][val],fun(x+i+1,val+1) + a[x+i]-a[x-1]);
    }
    return mem[x][val];
}
int main(){
    scanf("%d%d%d",&n,&k,&p);
    for (i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        a[i] += a[i-1];
    }
    if (p * k >= n) printf("%d",a[n]);
    else printf("%d",fun(1,0));
}