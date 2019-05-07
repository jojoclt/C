#include <iostream>
int N,n,i,cnt;
int main(){
    scanf("%d",&n);
    N = n;
    if (n%2 == 0){
        printf("error");
        return 0;
    }
    else {
        do{
            if (n < 0) break;
            for (i = 0; i < cnt; i++) printf(" ");
            for (i = 0; i < n; i++) printf("*");
            printf("\n");
        } while(n - 2 > 0, n -= 2, ++cnt);
        n+=2;cnt--;
        while (n + 2 <= N){
            n += 2; cnt--;
            for (i = 0; i < cnt; i++) printf(" ");
            for (i = 0; i < n; i++) printf("*");
            printf("\n");
        }
    }
}