#include<iostream>
using namespace std;
using ll = long long;
int n,w;
ll _max,sum;
int len;
int a[6000005];
int i;
int s,e;
int main() {
    scanf("%d%d",&n,&w);
    for (i = 0; i < n; i++){
        scanf("%d",&a[i]);
        sum += a[i];
        if (sum < 0){
            sum = 0;
            s = e = i+1;
        }
        else e = i;
        if (e-s+1 > w) sum -= a[s++];
        if (_max < sum){
            _max = sum;
            len = e-s+1;
        }
        else if (_max == sum){
            cout << i<<endl;
            if (len > e-s+1) len = e-s+1;
        }
       
        printf("max %lld len %d\n",_max,len);
    }
    printf("%lld\n%d",_max,len);
}