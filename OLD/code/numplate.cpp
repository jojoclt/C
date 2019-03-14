#include <bits/stdc++.h>
using namespace std;
char c[12];
string t,tmp;
int a,n,i,j,k;
int cnt;
queue <string> q;
map <string,int> m;
void f(int c,int d[]){
    for (int i = 0; i < c; i++){
        swap(t[k],t[d[i]]);
        if (!m[t]){
            q.push(t);
            m[t] = m[tmp] + 1;
        }
        //cout << t << "=" << m[t] << endl;
        t = tmp;
    }
}
int main(){
    bool flag3 = 0,flag2 = 0;
    scanf("%d",&a);
    for (j = 0; j < a; j++){
        scanf("%d",&n);
        if (n == 3 && !flag3){
                q.push("012345678");
                m["012345678"]=1;
                flag3 = !flag3;
        }
        else if (n == 2 && !flag2){
                q.push("0123");
                m["0123"]=1;
                flag2 = !flag2;
        }

        while (!q.empty()){
            // cnt++;
            t = q.front(); q.pop();
            tmp = t;
            if (n == 2){
                for (k = 0; k < 4; k++){
                    if (t[k] == '0'){
                        if (k == 0 || k == 3){
                            int x[] = {1,2};
                            f(2,x);
                        }
                        else if (k == 1 || k == 2){
                            int x[] = {0,3};
                            f(2,x);
                        }
                    }
                }
            }
            else if (n == 3){
                for (k = 0; k < 9; k++){
                    if (t[k] == '0'){
                        if (k == 0){
                            int x[] = {1,3};
                            f(2,x);
                        }
                        else if (k == 1){
                            int x[] = {0,2,4};
                            f(3,x);
                        }
                        else if (k == 2){
                            int x[] = {1,5};
                            f(2,x);
                        }
                        else if (k == 3){
                            int x[] = {0,4,6};
                            f(3,x);
                        }
                        else if (k == 4){
                            int x[] = {1,3,5,7};
                            f(4,x);
                        }
                        else if (k == 5){
                            int x[] = {2,4,8};
                            f(3,x);
                        }
                        else if (k == 6){
                            int x[] = {3,7};
                            f(2,x);
                        }
                        else if (k == 7){
                            int x[] = {4,6,8};
                            f(3,x);
                        }
                        else if (k == 8){
                            int x[] = {5,7};
                            f(2,x);
                        }
                    }
                }
            }
        }
        // cout << cnt;
        for (i = 0; i < n*n; i++)
            scanf(" %c",&c[i]);
        printf("%d\n",m[c]-1);
    }
}

/*
1
2
1 3
2 0

2
_______
2
3
0 1 2
3 4 5
6 7 8
3
1 2 0
3 4 5
6 7 8

0
2

_____________
2
3
3 0 1
4 8 2
6 5 7
3
4 1 5
0 2 8
3 6 7

9
11
*/
