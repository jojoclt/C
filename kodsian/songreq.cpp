#include<bits/stdc++.h>
using namespace std;
int N,M,Q,MINLIFT,tmp,minn = 1e9,cnt,i,j;
int lift[15],old[15],T[15],first,last,val,sum;
int stud[10000005],start[15];
bool rev(int x, int y) {return x > y;}
bool t1,t2;
bool pass(){
    MINLIFT = lift[1];
    minn = INT_MAX;
    for(j = 1 ; j <= N ; j++){  
        if(j!=1 && minn > stud[start[j]-1] - stud[start[j-1]-1]){
            first  = start[j-1];
            last = start[j]-1;
            minn = stud[start[j]-1] - stud[start[j-1]-1];
        }
    }
    for (j = first ; j <= last ; j++){
        val = stud[j] - stud[j-1];
        sum += val;
        if(sum > MINLIFT) cnt++,sum = 0,sum += val;
        if(val > MINLIFT) return false;
    }
    if(cnt > T[i] || pass == 0) return false;
    else return true;
    //printf("cnt = %d f %d l %d",cnt,first,last);
    cnt = 0;
}
int main(){
    scanf("%d%d%d",&N,&M,&Q);
    for(i = 1 ; i <= N ; i++) scanf("%d",&lift[i]);
    sort(lift+1,lift+N+1);
    for(i = 1 ; i <= N ; i++) scanf("%d",&old[i]);
    sort(old+1,old+N+1);
    for(i = 1 ; i <= M ; i++) scanf("%d",&stud[i]),stud[i] += stud[i-1];
    for(i = 1 ; i <= Q ; i++) scanf("%d",&T[i]);
    for(i = 1 ; i <= Q ; i++){
        for(j = 1 ;j <= N ; j++)
            scanf("%d",&start[j]),lift[j] -= old[j];
        
        for(i = 1 ; i <= N ; i++) lift[i] -= old[i];
        t1 = pass();
        for (j = 1; j <= N; j++)
    }


}