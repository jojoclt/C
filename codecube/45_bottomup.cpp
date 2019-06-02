#include <iostream>
using namespace std;
int n,k,p;
const int N = 100005;
int a[N],mem[2][N];
int main(){
	scanf("%d%d%d",&n,&k,&p);
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		a[i] += a[i-1];
	}
	if (p * k >= n) printf("%d",a[n]);
	else {
        for(int val = k; val >= 0; val--) {
            int flag = val%2;
            for(int x = n; x >= 1; x--) {
                mem[flag][x] = 0;
                if(x >= n || val == k) mem[flag][x] = 0;
                else { 
                    mem[flag][x] = mem[flag][x+1];
                    for(int i = 0; i < p; i++) {
                        mem[flag][x] = max(mem[flag][x], mem[!flag][x+i+1] + a[x+i] - a[x-1]);
                    }
                }
            }
        }
        printf("%d",mem[0][1]);
    }
}