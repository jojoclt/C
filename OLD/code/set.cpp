#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int a,b,c,i,j,tmp,cnt = 0;
set<int>y;
unordered_map <int,bool> m;
int x[1005],z[1005];//x z
int main(){
    scanf("%d%d%d",&a,&b,&c);
    for (i = 0; i < a; i++)
        scanf("%d",&x[i]);

    for (i = 0; i < b; i++){
        scanf("%d",&tmp);
        y.insert(tmp);
    }
    for (i = 0; i < c; i++)
        scanf("%d",&z[i]);

    sort(&x[0],&x[a]);
    sort(&z[0],&z[c]);
    for (i = 0; i < c; i++){
        for (j = 0; j < a; j++){
            if (z[i] > x[j]){
    
                if (y.find(z[i]-x[j]) != y.end()){
                    // printf("%d %d\n",z[i],x[j]);
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d",cnt);
}
