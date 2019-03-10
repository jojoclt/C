#include<stdio.h>
#include<math.h>
#include<string.h>
main(){
    FILE * fp;
    int i,j;
    char s[1005];
    fp=fopen("C:\\Users\\Kirin\\Desktop\\m e m e.txt","w");
    gets(s);
    for(i=0;i<strlen(s);i++){
        for(j=0;j<strlen(s);j++){
            if(i==0)fprintf(fp,"%c",s[j]);
            else if(j==i||j==0)fprintf(fp,"%c",s[i]);
            else fprintf(fp," ");
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}
