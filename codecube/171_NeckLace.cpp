#include <bits/stdc++.h>
using namespace std;
int n,t,u,i,t1,t2,cs;
stack <int> st;
unordered_map <int,set<int>> v;
unordered_map <int,int> m;
string c;
int main(){
    ios::sync_with_stdio(0);
    cin >> c >> n;
    cs = c.length();
    c += c;
    st.push(0);
    while (!st.empty()){
        t = st.top();
        st.push(++i);
        u = st.top();
        if (!st.empty() && c[t] == '(' && c[u] == ')'){
            v[t].insert(u);
            st.pop();
            st.pop();
            m[t] = u+1;
        }
    }
    for (i = 0; i < 5; i++)printf("m[%d] = %d\n",i,m[i]);
    //  return 0;
    for (i = 0; i < n; i++){
        cin >> t1 >> t2;
        if (t1 > t2) t2 += cs;
        --t1;--t2;
        if (v[t1].find(t2) != v[t1].end())
            cout << "yes\n";
        else {
            t = t1;
            while (t <= t2){
                cout << t << endl;
                cout<<"X";
                t = m[t];
            }
            if (++t2 == t) cout << "yes\n";
            else cout << "no\n";
        }
    }
}