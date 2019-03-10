#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    char n[1005],s[1005];
    int i,j;
    printf("ur name: ");scanf(" %s",n);
    printf("ur skool: ");scanf(" %s",s);
    for(i=0;i<strlen(n);i++){
        for(j=0;j<1<<28-1;j++){
            if(j==1<<28-2)printf("%c\n",n[i]);
        }
    }
    printf("\n");
    for(i=0;i<strlen(s);i++){
        for(j=0;j<1<<28-1;j++){
            if(j==1<<28-2)printf("%c\n",s[i]);
        }
    }
    return 0;
}

