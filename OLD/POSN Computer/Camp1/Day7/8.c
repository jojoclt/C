#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    char a[1005],b[1005];
    printf("a = ");scanf (" %[^\n]%*c", a);
    printf("b = ");scanf (" %[^\n]%*c", b);
    printf("c = %d",atoi(a)+atoi(b));
}

