#include <bits/stdc++.h>
#define pbit(x) cout<<bitset<4>(x);
using namespace std;
struct coor{
    int x,i;
};
int R,D,S,X;
int cnt,i;
int t1,t2;
int mem[2049][11];
int c1[2049][11],c2[2049][11];

stack <coor> st;
void c(int x, int y){
//    pbit(x);cout<<" "<<y<<endl;
    if (x == 1 << 1) return ;
    if (x != c1[x][y]){
        if (x < c1[x][y]) st.push({~x&c1[x][y],-1});
        else st.push({x&~c1[x][y],-2});
    }
    else{
        st.push({y,0});
    }
    c(c1[x][y],c2[x][y]);

}
vector <int> r[11],l[11];
queue <coor> q;
void B(int c, int d){
    printf("mem[");
    pbit(c);
    printf("][%d] = %d\n",d,mem[c][d]);
}
int main(){
//    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    while (cin >> R >> D >> S){
        bool xx = 0;
        if (!R && !D && !S) return 0;
        fill(&mem[0][0],&mem[1025][0],0);
        fill(&c1[0][0],&c1[1025][0],0);
        fill(&c2[0][0],&c2[1025][0],0);
        for (i = 0; i < 11; i++){
            r[i].clear();
            l[i].clear();
        }
        for (i = 0; i < D; i++){
            cin >> t1 >> t2;
            if (t1 == t2) continue;
            r[t1].push_back(t2);
            r[t2].push_back(t1);
        }
        for (i = 0; i < S; i++){
            cin >> t1 >> t2;
            if (t1 == t2) continue;
            l[t1].push_back(t2);
        }
        q.push({1<<1,1});
        while (!q.empty()){
            coor t = q.front(); q.pop();
            if (t.x == 1 << R){
                xx = 1;
                printf("Villa #%d\n",++cnt);
                printf("The problem can be solved in %d steps:\n",mem[t.x][t.i]);
                c(t.x,t.i);
                while (!st.empty()){
                    coor t = st.top(); st.pop();
//                    pbit(t.x);cout<<endl;
                    if (t.i){
                        int pos = 0,i = 1;
                        while (!(t.x&i)){
                            i = i << 1;
                            pos++;
                        }
                        if (t.i == -1) printf("- Switch off light in room %d.\n",pos);
                        else printf("- Switch on light in room %d.\n",pos);
                    }
                    else{
                        printf("- Move to room %d.\n",t.x);
                    }
                }
                cout<<endl;
                break;
            }
            for (i = 0; i < l[t.i].size(); i++){
                X = 1 << l[t.i][i];
                if (!(t.x & X) && !mem[t.x|X][t.i]){
                    q.push({t.x | X, t.i});
                    mem[t.x|X][t.i] = mem[t.x][t.i]+1;
                    c1[t.x|X][t.i] = t.x;
                    c2[t.x|X][t.i] = t.i;
//                    cout<<"A";
//                    B(t.x|X,t.i);
                }
                else if (t.x != X && !mem[t.x&~X][t.i]){
                    if (t.x & X == 1<<t.i) continue;
                    q.push({t.x & ~X, t.i});
                    mem[t.x&~X][t.i] = mem[t.x][t.i]+1;
                    c1[t.x&~X][t.i] = t.x;
                    c2[t.x&~X][t.i] = t.i;
//                    cout<<"B";
//                    pbit(t.x);cout<<" ";pbit(X);
//                    B(t.x&~X,t.i);
                }

            }
            for (i = 0; i < r[t.i].size(); i++){
                X = 1 << r[t.i][i];
                if (t.x & X && !mem[t.x][r[t.i][i]]){
                    q.push({t.x,r[t.i][i]});
                    mem[t.x][r[t.i][i]] = mem[t.x][t.i]+1;
                    c1[t.x][r[t.i][i]] = t.x;
                    c2[t.x][r[t.i][i]] = t.i;
//                    cout<<"C";
//                    B(t.x,r[t.i][i]);
                }
            }

        }
        if (!xx){
            printf("Villa #%d\n",++cnt);
            cout << "The problem cannot be solved.\n\n";
        }
        while(!q.empty())q.pop();

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
/*
10 11 41
1 5
1 7
1 8
2 3
2 8
2 10
3 9
4 6
5 7
5 9
6 8
2 1
6 1
8 1
4 2
8 2
9 2
10 2
1 3
2 3
4 3
5 3
6 3
8 3
3 4
9 4
10 4
3 5
6 5
8 5
1 6
2 6
3 6
1 7
2 7
4 7
6 7
8 7
10 7
4 8
6 8
7 8
3 9
4 9
6 9
7 9
8 9
2 10
6 10
7 10
8 10
9 10

0 0 0
*/
