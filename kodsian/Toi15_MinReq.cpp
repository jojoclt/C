#include <bits/stdc++.h>
using namespace std;
int N,M,Q;
int i,j,MINLIFT;
bool t1,t2;
int lift[15],old[15],stud[10000005],T[15],sim[15];
bool rev(int x, int y){return x > y;}
bool test(){

}
int main(){
    scanf("%d%d%d",&N,&M,&Q);
    for (i = 1; i <= N; i++) scanf("%d",&lift[i]);
    sort(lift+1,lift+N+1);
    for (i = 1; i <= N; i++) scanf("%d",&old[i]);
    sort(old+1,old+N+1);
    for (i = 1; i <= M; i++) scanf("%d",&stud[i]), stud[i] += stud[i-1];
    for (i = 1; i <= Q; i++) scanf("%d",&T[i]);

    for (i = 1; i <= Q; i++){
        for (j = 1; j <= N; j++){
            scanf("%d",&sim[j]);
        }
        t1 = test();
        sort(old+1,old+N+1,rev);
        t2 = test();
        if (t1 || t2) printf("P\n");
        else printf("F\n");
    }
}