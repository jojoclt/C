#include <bits/stdc++.h>
#define pbit(x) cout<<bitset<4>(x);
using namespace std;
bool operator < (const coor &l,const coor &r){
    if (l.x != r.x) return l.x < r.x;
    else return l.i < r.i;
} // for map as key
bool operator != (const coor &l, const coor &r){
    return l.x!=r.x && l.i!=r.i;
}
bool operator == (const coor &l, const coor &r){
    return l.x==r.x && l.i==r.i;
}
struct coor{
    int x,i;
};
int R,D,S,X;
int query,i;
int t1,t2;
int mem[1025][10];

void B(int c, int d){
    printf("mem[");
    pbit(c);
    printf("][%d] = %d\n",d,mem[c][d]);
}
int main(){
    while (cin >> R >> D >> S){
        vector <int> r[11],l[11];
        queue <coor> q;
        fill(&mem[0][0],&mem[1025][0],0);
        if (!R && !D && !S) return 0;
        for (i = 0; i < D; i++){
            cin >> t1 >> t2;
            r[t1].push_back(t2);
            r[t2].push_back(t1);
        }
        for (i = 0; i < S; i++){
            cin >> t1 >> t2;
            l[t1].push_back(t2);
        }
        q.push({1<<1,1});
        while (!q.empty()){
            coor t = q.front(); q.pop();
            if (t.x == 1 << R){
                cout << mem[t.x][t.i];
                return 0;
            }
            for (i = 0; i < l[t.i].size(); i++){
                X = 1 << l[t.i][i];
                if (!(t.x & X) && !mem[t.x|X][t.i]){
                    q.push({t.x | X, t.i});
                    mem[t.x|X][t.i] = mem[t.x][t.i]+1;
                    cout<<"A";B(t.x|X,t.i);
                }
                else if (t.x!=X && !mem[t.x&~X][t.i]){
                    q.push({t.x & ~X, t.i});
                    mem[t.x&~X][t.i] = mem[t.x][t.i]+1;
                    cout<<"B";
                    pbit(t.x);cout<<" ";pbit(X);B(t.x&~X,t.i);
                }
//                B(t.x,t.i);
            }
            for (i = 0; i < r[t.i].size(); i++){
                X = 1 << r[t.i][i];
                if (t.x & X && !mem[t.x][r[t.i][i]]){
                    q.push({t.x,r[t.i][i]});
                    mem[t.x][r[t.i][i]] = mem[t.x][t.i]+1;
                    cout<<"C";B(t.x,r[t.i][i]);
                }
            }

        }
//        printf("Villa #%d\n",++query);
    }
}
/*
3 3 4
1 2
1 3
3 2
1 2
1 3
2 1
3 2

2 1 2
2 1
1 1
1 2

0 0 0
*/
