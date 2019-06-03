#include<bits/stdc++.h>
using namespace std;
int N,arr[1000005],i,val[100005],t;
stack<int>sl,sr;
int main(){
    scanf("%d",&N);
   arr[0] = 1e9;
    for(i = 1 ; i <= N ; i++){
        scanf("%d",&arr[i]);
        val[i] = 1;
    }
    arr[N+1] = 1e9;
    for(i = 1 ; i <= N+1 ; i++){
        if(!sr.empty() && arr[i] > arr[sr.top()]){
            t = sr.top() ; sr.pop();
            val[t] += i-t-1;
        }
        sr.push(i);
    }
    // for(i = N ; i >= 0 ; i--){
    //     if(!sr.empty() && arr[i] > arr[sr.top()]){
    //         t = sr.top(); sr.pop();
    //         val[t] += t-i-1;
    //     }
    //     sr.push(i);
    // }
    // for(i = 1 ; i <= N ; i++){
    //     printf("%d")
    // } 
    for(i = 1 ; i <= N ; i++){
        printf("%d ",val[i]);
    }
}