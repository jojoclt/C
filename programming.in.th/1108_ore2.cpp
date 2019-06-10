#include <bits/stdc++.h>  
using namespace std;
using ll = long long;
const int N = 1e6+5;
int n,k;
int arr[N];
ll S = 0;
ll findMaxSubarraySum(int n, int k){  
    ll curr_sum = arr[0], max_sum = 0; int start = 0;  
    for (int i = 1; i < n; i++) {
        bool ok = false;
        while (curr_sum + arr[i] > k && start < i) { 
            ok = true; 
            curr_sum -= arr[start];  
            start++;  
        }
        if (curr_sum <= k) max_sum = max(max_sum, curr_sum);  
        if (ok){
            S += max_sum;
            max_sum = 0;
        }
        curr_sum += arr[i];  
    }  
    return S;  
}  

int main(){  
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) scanf("%d",&arr[i]);
    printf("%lld",findMaxSubarraySum(n,k));
}  