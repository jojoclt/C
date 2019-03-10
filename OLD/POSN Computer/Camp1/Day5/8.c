#include<stdio.h>
#include<string.h>
main(){
    char x[1005];
    int n,c,v,i;
    n=c=v=0;
    scanf("%[^\n]%*c",&x);
    for(i=0;i<strlen(x);i++){
        if (x[i]>='0'&&x[i]<='9'){n++;c++;}
        if (x[i]>='a'&&x[i]<='z')c++;
        if (x[i]>='A'&&x[i]<='Z')c++;
        if (x[i]=='a'||x[i]=='A'||x[i]=='e'||x[i]=='E'||x[i]=='i'||x[i]=='I'||x[i]=='o'||x[i]=='O'||x[i]=='u'||x[i]=='U')v++;
    }
    printf("Number = %d Character = %d Vowel = %d",n,c,v);
}
