#include<stdio.h>
#include<string.h>
main(){
    char s[1005];
    int j,a,e,i,o,u;
    a=e=i=o=u=0;
    printf("Your string: ");scanf ("%[^\n]%*c", s);
    printf("String length: ");printf("%d\n",strlen(s));
    printf("String reversed: ");
    for (j=strlen(s)-1;j>=0;j--)printf("%c",s[j]);
    printf("\nAll caps: ");
    for (j=0;j<strlen(s);j++){
        if(s[j]>='a'&&s[j]<='z')printf("%c",s[j]+'A'-'a');
        else printf("%c",s[j]);
        if(s[j]=='a'||s[j]=='A')a++;
        if(s[j]=='e'||s[j]=='E')e++;
        if(s[j]=='i'||s[j]=='I')i++;
        if(s[j]=='o'||s[j]=='O')o++;
        if(s[j]=='u'||s[j]=='U')u++;
    }
    printf("\nVowels:");
    printf("\nA or a: %d",a);
    printf("\nE or e: %d",e);
    printf("\nI or i: %d",i);
    printf("\nO or o: %d",o);
    printf("\nU or u: %d",u);
}
