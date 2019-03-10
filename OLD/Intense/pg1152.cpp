#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,tmp,c;
int a[1000][1000];
priority_queue <int> heap;

int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        for (j = 0; j <n; j++)
            scanf("%d",&a[i][j]);

    for (i = n-1; i >= 0; i--){
        for (j = i, k = n-1; j < n; j++, k--){
            heap.push(a[j][k]);
            //printf("%d %d\n",j,k);
        }
        cout<< heap.top()<<endl;
        c += heap.top();
        heap.pop();
    }
    for (i = n-2; i > 0; i--){
        for (j = i, k = 0; j >= 0; j--, k++){
            heap.push(a[j][k]);
            //printf("%d %d\n",j,k);
        }
        cout <<heap.top()<<endl;
        c += heap.top();
        heap.pop();
    }


    printf("%d",c);

}
