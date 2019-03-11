#include <iostream>
using namespace std;
char cc;
int t,n,i;
long long a,b,c = 1;
bool check;
int main(){
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        scanf(" %c%d",&cc,&t);
        if (cc == '+') a += t;
        else if (cc == 'x'){
            if (!t) check = true;
            else c *= t;
        }
        else if (cc == '-') b += t;
    }
    if (check) b = 0;
    printf("%lld",a*c-b);
}