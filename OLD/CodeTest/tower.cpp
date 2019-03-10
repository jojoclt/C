#include <bits/stdc++.h> //pg1031
using namespace std;

int k,m,n,i,j,a,b,d = -1;

vector <int> v[10001];
int mem[10000];

int tower(int x, int y){
    if (y == k){
        d = max(d,x);
    }
    if (y < k){
        for (i = 0; i < v[x].size(); i++){
            tower(v[x][i],y+1);
        }
    }
}
int main(){
    scanf("%d%d%d",&k,&n,&m);
    for (i = 0; i < m ; i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }
    tower(1,0);
//    for (i = 0; i < n ; i++){
//        printf("%d ",v[i].size());
//    }
    printf("%d",d);

}
/*
2 6 5
1 2
1 3
2 5
3 4
5 6
*/
