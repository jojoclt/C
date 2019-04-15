#include <cstdio>
using namespace std;
int n,i,t;
const int M = 997;
int powxy(int x, int y) {
    if (y == 0) return 1;
    if (y%2 == 1) return ((long long)x*powxy(x, y-1))%M;
    int t = powxy(x, y/2);
    return (t*t)%M;
}
int f(int x){
    return ((2*powxy(-1,x)) + powxy(4,x));
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&t), printf("%d ",f(t)%997);
} 