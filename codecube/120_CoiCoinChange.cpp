#include <bits/stdc++.h>
using namespace std;
int n,l,c;
int a[15];
int mem[1000005][2],query[15][2];
int i,j,c1,c2,v,ans;
int main(){
    scanf("%d%d%d",&n,&l,&c);
    for (i = 0; i < c; i++)
        scanf("%d",&a[i]);
    for (i = 1; i <= l; i++) mem[i][0] = 1e7;
    mem[0][0] = 0;
    for (i = 0; i <= l; i++){
        for (j = 0; j < c; j++){
            if (a[j] + i <= l){
                if (mem[i+a[j]][0] > mem[i][0] + 1){
                    mem[i+a[j]][0] = mem[i][0] + 1;
                    mem[i+a[j]][1] = j;
                }
            }
        }
    }
//    for (i = 1; i <= l; i++) printf("track[%d] = %d\n",i,mem[i][1]);
    v = 1e7;
    for (i = n; i <= l; i++){
        if (mem[i][0] + mem[i-n][0] < v){
            c1 = mem[i][0];
            c2 = mem[i-n][0];
            v = c1+c2;
            ans = i;
        }
    }
//    cout << ans<<endl;
    for (i = ans; i != 0; i -= a[mem[i][1]]){
        j = mem[i][1];
        query[j][0]++;
    }
    for (i = ans-n; i != 0; i-= a[mem[i][1]]){
        j = mem[i][1];
        query[j][1]++;
    }
    printf("%d %d\n",c1,c2);
    for (i = 0; i < 2; i++){
        for (j = 0; j < c; j++)
            printf("%d ",query[j][i]);
        printf("\n");
    }
}
