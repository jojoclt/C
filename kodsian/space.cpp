#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,t;
bool m[1<<15];
int main(){
    scanf("%d",&n);
    for (k = 0; k < (1<<n); k++){
        m[k] = true;
        for (i = 0; i < n; i++){
            t = k|(1<<i);
            if (!m[t] && t != k){
                // m[t] = true;
                for (j = n-1; j >= 0; j--)
                    if (k&(1<<j)) printf("1");
                    else printf("0");
                
                printf(" ");
                for (j = n-1; j >= 0; j--)
                    if (t&(1<<j)) printf("1");
                    else printf("0");
                
                printf("\n");
            }
        } 
    }
}