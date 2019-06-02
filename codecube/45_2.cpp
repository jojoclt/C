#include <iostream>
using namespace std;
int n,k,p;
int flag;
const int N = 100005;
int a[N],mem[2][N],mx;
int main(){
	scanf("%d%d%d",&n,&k,&p);
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		a[i] += a[i-1];
	}
    if (p*k >= n) {
        printf("%d",a[n]);
        return 0;
    }
    for (int val = 1; val <= k; val++){
        int flag = val%2;
        for (int i = p; i <= n; i++){
            mem[flag][i] = mem[flag][i-1];
            mem[flag][i] = max(mem[flag][i],mem[!flag][i-p] +a[i]-a[i-p]);
            mx = max(mem[flag][i],mx);
        }
    }
    printf("%d",mx);
}