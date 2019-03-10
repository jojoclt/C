#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    char c[100005],t1,t2;
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf("%s",c);
        stack <char> stck;
        stck.push(c[0]);
        while (!stck.empty()){
            for (j = 1; j < stck.size(); j++){
                if ((stck.top() == '(' || stck.top() == '[' || stck.top() == '{') &&
                 (c[j] == '(' || c[j] == '[' || c[j] == '{' )){
                 stck.push(c[j]);
                 printf("Fu\n");
                 }
            }
        }
//        for (j = 1; j < strlen(c); j++){
//            if ((stck.top() == '(' || stck.top() == '[' || stck.top() == '{') &&
//                 (c[j] == '(' || c[j] == '[' || c[j] == '{' )){
//                 stck.push(c[j]);
//                 printf("Fu\n");
//                 }
//            else if ((c[j] == '}' && stck.top() == '{') ||
//                     (c[j] == ')' && stck.top() == '(') ||
//                     (c[j] == ']' && stck.top() == '[')){
//                         stck.pop();
//                         printf("Ck\n");
//                     }
//            else {
//                printf("%dBREAK\n",i);
//                break;
//            }
//
//        }
    }
}
