#include <bits/stdc++.h>
using namespace std;
int a[] = {-1,-2,-3,-4,-5}, n = 5,i,t,m=-1e9;
int main(){
    /*
    for (i = 0; i < n; i++){
        t += a[i];
        if (t < 0) t = 0;
        m = max(m,t);
    }// IF VAL >= 0
    */
    for (i = 0; i < n; i++){
        t += a[i];
        m = max(m,t);
        if (t < 0) t = 0;
    }// IF VAL < 0
    cout << m;
}
