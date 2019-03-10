#include <bits/stdc++.h>
using namespace std;
int mem[1000][1000];
int x,i,j,n,a[10000],cnt = 0;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (x = 0; x < n; x++){
        if (a[x] > a[x+1] && x + 1 < n){
            if (a[x+1] == 1){
                a[x+1] = a[x] +1;
                cnt++;
                //printf("%da\n",x);
            }
            else{
                a[x] = a[x+1]-1;
                cnt++;
                //printf("%db\n",x);
            }
        }
        else if (a[x] == a[x+1]){
            if (a[x] - 1 > a[x-1]){
                a[x]--;
                cnt++;
                //printf("%dc\n",x);
            }
            else{
                a[x+1]++;
                cnt++;
                //printf("%dd\n",x);
            }
        }
//        for (i = 0; i < n; i++){
//        printf("%d ",a[i]);
//    }
//    printf("\n");

    }
//    for (i = 0; i < n; i++){
//        printf("%d ",a[i]);
//    }
    printf("%d",cnt);
}
