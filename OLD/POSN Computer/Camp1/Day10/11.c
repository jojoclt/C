#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    char n[1005],s[1005][1005];
    int i,j,a,b,c[1005];
    a=b=0;
    scanf(" %s",n);
    for(i=0;i<strlen(n);i++){
        if(n[i]<'0'||n[i]>'9'){
            printf("error");
            return 0;
        }
    }
    for(i=0;i<strlen(n);i++){
        c[i]=0;
        s[a][b]=n[i];
        if(n[i]=='0'){a++;b=0;}
        else b++;
    }
    for(i=0;i<a;i++){
        for(j=0;j<a;j++){
            if(strcmp(s[i],s[j])==0){
                if(j<i)break;
                else c[i]++;
            }
        }
    }
    for(i=0;i<a;i++){
        if(c[i]>0){
            printf("%10s %d\n",s[i],c[i]);
        }
    }
    /*for(i=0;i<a;i++){
        for(j=0;j<strlen(s[i]);j++){
            printf("%c",s[i][j]);
        }
        printf("\n");
    }*/
}

