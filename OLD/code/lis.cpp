#include <bits/stdc++.h> //longest increasing subsequence
using namespace std;
int n,i,a[1000],mem[1000][1000];
int lis(int i, int last){
    if (mem[i][last]) return mem[i][last];
    if (i == n) mem[i][last] = 0;
    else{
        if (a[i] > last) mem[i][last] = lis(i+1,a[i]) + 1;
        mem[i][last] =  max(mem[i][last],lis(i+1,last));
        //printf("mem[%d][%d] = %d\n",i,last,mem[i][last]);
    }
    return mem[i][last];
}
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    printf("%d",lis(0,-1));//printf("%d",lis(0,0));
}

//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int a[1001];
//int mem[1001][1001];
//int f(int x,int last)
//{
//    if(x==n)return 0;
//    else if(!mem[x][last])
//    {
//        if(a[x]>last)mem[x][last] = f(x+1,a[x])+1;
//        mem[x][last] = max(mem[x][last],f(x+1,last));
//    }
//    return mem[x][last];
//}
//main()
//{
//    int i;
//     scanf("%d",&n);
//     for(i=0;i<n;i++)scanf("%d",&a[i]);
//     printf("%d",f(0,-1));
//}
