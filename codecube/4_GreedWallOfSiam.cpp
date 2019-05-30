#include <iostream>
using namespace std;
using ll = long long;
int n,t,a[100005];
ll sum,res;
int gcd(int a, int b){
    return a ? gcd(b%a,a) : b; 
}
int findGCD(int arr[], int n){
    res = arr[0];
    for (int i = 1; i < n; i++) res = gcd(arr[i],res);
    return res;
}

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    res = findGCD(a,n);
    for (int i = 0; i < n; i++){
        sum += (a[i]/res);
    }
    printf("%lld",sum);
}