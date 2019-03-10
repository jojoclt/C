#include <iostream>
#include <climits>
using namespace std;

#define A 100
#define B 9900
#define C 990000
int a,b;
int prc[] = {A,B,C}, rng[] = {2*A,3*B,5*C};
int amo[] = {2,3,5,7};
int i,n,l,r,mid,val,t1,t2;
int M_V(int x){
    if (x == 0) return 0;
    int cnt = 0;
    for (i = 0; i < 3; i++){
        if (x >= rng[i]){
            x -= rng[i];
            cnt += prc[i];
        }
        else break;
    }
    cnt += x/amo[i];
    return cnt;
}
int V_M(int x){
    if (x == 0) return 0;
    int pay = 0;
    for (i = 0; i < 3; i++){
        if (x >= prc[i]){
            x -= prc[i];
            pay += rng[i];
        }
        else break;
    }
    pay += x*amo[i];
    return pay;
}
int main(){
    ios::sync_with_stdio(0);
    while (scanf("%d%d",&a,&b),a && b){
        n = M_V(a);
        l = 0; r = n;
        while (l <= r){
            mid = l+r>>1;
            t1 = V_M(mid); t2 = V_M(n-mid);
            // printf("%d %d\n",t1,t2);  
            val = abs(t1-t2);
            if (val > b) r = mid-1;
            else if (val < b) l = mid+1;
            else break;
            
        }
        l = V_M(mid); r = V_M(n-mid);
        cout << min(l,r) << "\n";
    }
}