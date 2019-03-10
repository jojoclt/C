#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>
int an(char s1[20000],char s2[20000]){
    int i,j,k;
    char tmp;
    k=0;
    for(i=0;i<strlen(s1);i++){
        for(j=k;j<strlen(s2);j++){
            if(s1[i]>='a'&&s1[i]<='z'){
                if(s1[i]==s2[j]||s1[i]==s2[j]+32){
                    tmp=s2[j];
                    s2[j]=s2[k];
                    s2[k]=tmp;
                    k++;
                    break;
                }
            }
            else if(s1[i]>='A'&&s1[i]<='Z'){
                if(s1[i]==s2[j]||s1[i]==s2[j]-32){
                    tmp=s2[j];
                    s2[j]=s2[k];
                    s2[k]=tmp;
                    k++;
                    break;
                }
            }
            else break;
        }
        if(j==strlen(s2))return 0;
    }
    return 1;
}
main(){
    int n,i,j,k;
    char s1[20000],s2[20000];
    while(1){
        scanf("%d",&n);
        if (n<=0||n>=10000)printf("Invalid number. Try again.\n");
        else break;
    }
    int a[n];
    for(i=0;i<n;i++){
        scanf(" %[^\n]%*c",&s1);
        scanf(" %[^\n]%*c",&s2);
        a[i]=an(s1,s2);
    }
    for(i=0;i<n;i++){
        if(a[i]==1)printf("\nyes");
        else if (a[i]==0) printf("\nno");
    }
}

