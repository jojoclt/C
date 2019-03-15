#include <bits/stdc++.h>
using namespace std;;
int T = 20,i;
char c[256];
int mem[256][256];
int main(){
    while (T--){
        scanf("%d",&n);
        scanf("%s",c);
        for (i = 0; i < n; i++){
            if (c[i] == '0') mem[i][i] = 1 << 0;
            else if (c[i] == '1') mwm[i][i] = 1 << 1;
            else if (c[i] == '2') mem[i][j] = 1 << 2;
        }
        if (segi(0,n-1) & 1 << 0) printf("yes\n");
        else printf("no\n");
    }
}