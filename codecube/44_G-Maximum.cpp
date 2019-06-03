#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,i,T;
int a[N],t[N];
stack <int> st;
int main(){
    scanf("%d",&n);
    t[0] = t[n+1] = 1e9;
    for (i = 1; i <= n; i++) scanf("%d",&t[i]),a[i] = 1;
    for (i = 1; i <= n+1; i++){
        while (!st.empty() && t[i] > t[st.top()]){
            T = st.top(); st.pop();
            a[T] += i-T-1;
            // printf("%d: a[%d] = %d\n",i,T,i-T-1);
        }
        st.push(i);
    }
    for (i = n; i >= 0; i--){
        while (!st.empty() && t[i] > t[st.top()]){
            T = st.top(); st.pop();
            a[T] += T-i-1;
            // printf("%d: a[%d] = %d\n",i,T,T-i-1);
        }
        st.push(i);
    }
    for (i = 1; i <= n; i++) printf("%d ",a[i]);
}