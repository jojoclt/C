#include <bits/stdc++.h>
using namespace std;
int a[105][45];
bool c[105][45];
int track[105][45];
int aa,s,bb,ans,pos;
int i,j,t;
stack <int> st;
int main(){
    ios::sync_with_stdio(0);
    cin >> bb >> s >> aa;
    for (i = 1; i <= aa; i++)
        for (j = 1; j <= bb; j++)
            cin >> a[i][j];
    c[0][s] = true;
    for (i = 1; i <= aa; i++){
        for (j = 1; j <= bb; j++){
            if (c[i-1][j]){
                if (!a[i][j-1]){
                    c[i][j-1] = true;
                    track[i][j-1] = 1;
                }
                if (!a[i][j]){
                    c[i][j] = true;
                    track[i][j] = 3;
                }
                if (!a[i][j+1]){
                    c[i][j+1] = true;
                    track[i][j+1] = 2;
                }
            }
        }
    }
    // for (i = 1; i <= aa; i++){
    //     for (j = 1; j <= bb; j++) cout << track[i][j] << " ";
    //     cout<<endl;
    // }
    for (i = 1; i <= bb; i++)
        if (!a[aa][i] && c[aa][i]) t = i;
    int tc = track[aa][t];
    for (i = aa; i > 0; i--){
        st.push(tc);
        if (tc == 1) tc = track[i-1][t+1], t += 1;
        else if (tc == 3) tc = track[i-1][t];
        else if (tc == 2) tc = track[i-1][t-1], t -= 1;
    }
    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
}