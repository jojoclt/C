#include <bits/stdc++.h>
using namespace std;
int n,i,j,cnt;
string a,b,t,T;
queue <string> q;
map<string,int> m;
map<string,pair<int,int>> track;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    q.push(a);
    while (!q.empty()){
        t = q.front(); q.pop();
        if (t == b){
            cout << m[t]<<endl;
            while (t != a && cnt++ <= 1e5){
                T = t;
                i = track[t].first;
                j = track[t].second;
                printf("%d %d\n",i+1,(j)?-1:1);
                if (j){
                    T[i]++; T[i+1]++;
                }
                else{
                    T[i]--; T[i+1]--;
                }
                t = T;
            }
            return 0;
        }
        for (i = 0; i < n-1; i++){
            T = t;
            if (T[i] == '0'){
                T[i]++; T[i+1]++;
                if (m[T]) continue;
                m[T] = m[t]+1;
                track[T] = {i,0};
                q.push(T);
            }
            else if (T[i] == '9'){
                T[i]--, T[i+1]--;
                if (m[T]) continue;
                m[T] = m[t]+1;
                track[T] = {i,1};
                q.push(T);
            }
            else{
                T[i]++; T[i+1]++;
                if (T[i+1] == '9'+1) T[i+1] = '0';
                if (!m[T]){
                    m[T] = m[t]+1;
                    track[T] = {i,0};
                    q.push(T);
                }

                T = t;
                T[i]--; T[i+1]--;
                if (T[i+1] == '0'-1) T[i+1] = '9';
                if (m[T]) continue;
                m[T] = m[t]+1;
                track[T] = {i,1};
                q.push(T);
            }
        }
    }
    cout << -1;
}
