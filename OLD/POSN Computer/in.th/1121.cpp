#include<bits/stdc++.h>
using namespace std;
int n,N;
int a[100000];
main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char x[100000];
        scanf("%s",x);
        stack<char>s;
        N=strlen(x);
        for(int j=0;j<N;j++){
            s.push(x[j]);
            if(s.top()==')'){
                s.pop();
                if(s.empty()||s.top()!='('){
                    a[i]=1;
                    break;
                }
                else {s.pop();}
            }
            else if(s.top()==']'){
                s.pop();
                if(s.empty()||s.top()!='['){
                    a[i]=1;
                    break;
                }
                else {s.pop();}
            }
            else if(s.top()=='}'){
                s.pop();
                if(s.empty()||s.top()!='{'){
                    a[i]=1;
                    break;
                }
                else {s.pop();}
            }
        }
        if(!s.empty())a[i]=1;
    }
    for(int i=0;i<n;i++){
        if(a[i])printf("no\n");
        else printf("yes\n");
    }
}
