#include <cstdio>
using namespace std;
int a[505];
int n,k;
int i,j,t;
int flag = 1;
int mem[2][50005];
int main(){
    //using flag save mem and the !flag see the last one;
    scanf("%d%d",&n,&k);
    for (i = 1; i <= n; i++) scanf("%d",&a[i]);
    mem[0][0] = 1;
    for (i = 1; i <= n; i++){
        for (j = 0; j <= k; j++){
            mem[flag][j] = mem[(!flag)][j]%1000007;
            if (j >= a[i]) mem[flag][j] = (mem[flag][j] + mem[(!flag)][j-a[i]])%1000007;
        }
        flag = !flag;
    }
    printf("%d",mem[!flag][k]);
}
