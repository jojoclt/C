#include <iostream>
#define RECUR 1
using namespace std;
int T,n,k,i,j;
bool mem[10005][100],visit[10005][100];
int a[10005];
bool f(int x, int y){
    if (x == n){
        if (y == 0) return 1;
        return 0;
    }
    if (visit[x][y]) return mem[x][y];
    visit[x][y] = true;
    return mem[x][y] = max(f(x+1,(y+a[x]+k)%k),f(x+1,(y-a[x]+k)%k));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--){
        fill(&mem[0][0],&mem[10004][99],0);
        fill(&visit[0][0],&visit[10004][99],0);
        cin >> n >> k;
        for (i = 0; i < n; i++){
            cin >> a[i];
            a[i] = abs(a[i])%k;
        }
        if (RECUR){
            printf(f(1,a[0]) ? "Divisible\n":"Not divisible\n");
        }
        else{   
            mem[0][0] = true;
            for (i = 0; i < n; i++){
                for (j = 0; j < k; j++){
                    if (mem[i][j]) mem[i+1][(j+a[i]+k)%k] = mem[i+1][(j-a[i]+k)%k] = true;
                }
            }
            printf(mem[n][0] ? "Divisible\n":"Not divisible\n");
        }
    }
}