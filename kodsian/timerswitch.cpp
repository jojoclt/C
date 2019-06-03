#include <bits/stdc++.h>
using namespace std;
int n,i;
string p,s;
int b[5000005];
void kmpPreprocess(){
    int i = 0, j = -1; b[0] = -1;
    while (i < n){
        while (j >= 0 && p[i] != p[j]) j = b[j];
        i++,j++;
        b[i] = j;
    }
}
int kmpSearch(){
    int i = 1, j = 0;
    while(i < n*2){
        while (j >= 0 && s[i] != p[j]) j = b[j];
        i++,j++;
        if (j == n){
            j = b[j];
            return i;
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    cin >> p;
    s = p+p;
    kmpPreprocess();
    // for (i = 0; i < n; i++) printf("%d ",b[i]);
    printf("%d",kmpSearch()-n);
}