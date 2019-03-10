#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    FILE *fp;
    char s[3];
    int i,j,k=0;
    scanf(" %s",s);
    if(strcmp(s,"add")==0){
        char tel[10],name[1005],sur[1005];
        scanf(" %s",tel);scanf(" %s",name);scanf(" %s",sur);
        fp=fopen("E:\\POSN Computer\\Day9\\t.txt","a");
        fprintf(fp,"\n%s %s %s",tel,name,sur);
        fclose(fp);
    }
    else if(strcmp(s,"src")==0){
        fp=fopen("E:\\POSN Computer\\Day9\\t.txt","r");
        char n[10],tmp[1005];
        scanf(" %s",n);
        for(j=0;j<1005;j++){
            fscanf(fp," %s",tmp);
            for(i=0;i<strlen(n);i++){
                if(n[i]!=tmp[i])
                    break;
                else continue;
            }
            if(i==strlen(n)){
                for(i=0;i<2;i++){
                    printf("%s ",tmp);
                    fscanf(fp," %s",tmp);
                }
                printf("%s\n",tmp);
                k++;
            }
        }
        if(k==0)printf("none");
    }
    return 0;
}
