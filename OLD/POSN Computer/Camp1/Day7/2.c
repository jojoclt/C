#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    int x,i;
    char s[1005];
    printf("Move letters back by: ");scanf("%d",&x);
    printf("Your string: ");scanf (" %[^\n]%*c", s);
    for(i=0;i<strlen(s);i++){
        if (s[i]>='a'&&s[i]<='z'){
            s[i]-=x;
            while(1){
                if (s[i]<'a')
                    s[i]+=26;
                else if (s[i]>'z')
                    s[i]-=26;
                else break;
            }
        }
        if (s[i]>='A'&&s[i]<='Z'){
            s[i]-=x;
            while(1){
                if (s[i]<'A')
                    s[i]+=26;
                else if (s[i]>'Z')
                    s[i]-=26;
                else break;
            }
        }
        printf("%c",s[i]);
    }
}

