#include<string.h>
int main(){
    char c[1005];
    int i,j,k,a[1005],b[1005],n=0;
    int max=1-1<<31;
    scanf("%s",c);
    char d[strlen(c)];
    for(i=0;i<strlen(c);i++){
        if(c[i]=='A')d[i]='T';
        else if(c[i]=='T')d[i]='A';
        else if(c[i]=='C')d[i]='G';
        else if(c[i]=='G')d[i]='C';
    }
    //printf("%s,%s\n",c,d);
    for(i=0;i<strlen(c);i++){
        for(j=strlen(c)-1;j>i;j--){
            if(c[i]==d[j]){
                a[n]==i;
                k==i;
                n++;
                while(1){
                    k++;j--;
                    if(c[k]!=d[j]){
                        n--;
                        break;
                    }
                    else if(j==a[n-1]){
                        b[n]=k;
                        break;
                    }
                }
            }
        }

    }
    for(i=0;i<n;i++){
        if(b[n]-a[n]+1>max)max=b[n]-a[n]+1;
    }
    printf("%d\n%d\n",max,n);
    for(i=0;i<n;i++){
        printf("%d\n",a[n]+1);
        for(j=0;j<b[n]-a[n]+1;j++){
            printf("%c",c[j]);
        }
        printf("\n");
        for(j=0;j<b[n]-a[n]+1;j++){
            printf("%c",d[j]);
        }
        printf("\n");
    }
    return 0;
}
