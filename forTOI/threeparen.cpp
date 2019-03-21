#include <bits/stdc++.h>
using namespace std;

int n,N,i,j;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        char a[100000];
        stack <char> s;
        bool x = 1;
        scanf("%s",a);
        N=strlen(a);
        for (j = 0; j < N; j++){
            s.push(a[j]);
            if (s.top() == ')'){
                s.pop();
                if (s.empty()||s.top()!='('){
                    x = 0;
                    break;
                }
                else s.pop();
            }
            else if (s.top() == '}'){
                s.pop();
                if (s.empty()||s.top()!='{'){
                    x = 0;
                    break;
                }
                else s.pop();
            }
            else if (s.top() == ']'){
                s.pop();
                if (s.empty()||s.top()!='['){
                    x = 0;
                    break;
                }
                else s.pop();
            }
        }
        if (!s.empty()) x = 0;

        if (x) printf("yes\n");
        else printf("no\n");
    }
}
