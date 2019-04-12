#include <bits/stdc++.h>
using namespace std;
int t,n,p,a[20];
int i;
int mem[21][1001];
int f(int x,int val){
    cout << x << " " << val<<endl;
    if (val > 1000) return 0;
    if (mem[x][val] != -1) return mem[x][val];
    if (val == p) mem[x][val] = 1;
    else mem[x][val]= 0;
    return mem[x][val] += f(x+1,val+a[x+1]) + f(x+1,val);
}


//int f(int x,int val){
//    if (x == p) return 0;
//    if (val == n){
//        k = 1;
//        return 1;
//    }
//    f(x+1,val+a[x]);
//    f(x+1,val);
//
//}
int main(){
    cin >> t;
    while (t--){
        fill(begin(a),end(a),0);
        fill(&mem[0][0],&mem[21][0],-1);
        cin >> p >> n;
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = 0; i < n;)
        f(0,0);
        cout << mem[n][p];
    }
}
