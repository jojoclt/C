#include<stdio.h>
#include<math.h>
#include<string.h>
/*
ABCDEFIJ 4
1 L 5
2
1 R 3
2
*/
main(){
    char s[1005];
    int n,i,j;
    scanf(" %s",s);
    scanf("%d",&n);
    char c[3*n],r[strlen(s)];
    for(i=0;i<n;i++){
        scanf(" %c",&c[i]);
        if(c[i]=='1'&&c[i-2]!='1'){
            n+=2;
        }
    }
    for(i=0;i<n;i++){
        if(c[i]=='1'){
            i++;
            if(c[i]=='R'){
                i++;
                for(j=0;j<strlen(s);j++){
                    r[j]=s[(j+c[i]-'0')%strlen(s)];
                }
                for(j=0;j<strlen(s);j++){
                    s[j]=r[j];
                }
            }
            else if(c[i]=='L'){
                i++;
                for(j=0;j<strlen(s);j++){
                    r[j]=s[(j-c[i]+'0')%strlen(s)];
                }
                for(j=0;j<strlen(s);j++){
                    s[j]=r[j];
                }
            }
            else return 0;
        }
        else if(c[i]=='2'){
            printf("%s\n",s);
        }
        else return 0;
    }
}
