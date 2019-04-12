#include <bits/stdc++.h>
using namespace std;
int a[2505],n,i,high,t;
int e = -1;
stack <int> st;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%d",&a[i]);
        t += a[i];
        high = max(t,high);
        if (t < 0) t = 0;
    }
    if (!high){
        cout << "Empty sequence";
        return 0;
    }
    t = 0;
    for (i = 0; i < n; i++){
        t += a[i];
        if (t < 0) t = 0;
        if (t == high){
            e = i;
            break;
        }
    }
    t = high;
    for (i = e;t!=0;i--){
        st.push(a[i]);
        t -= a[i];
    }
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl << high;
}
