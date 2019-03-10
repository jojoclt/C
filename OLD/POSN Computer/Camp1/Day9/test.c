#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    FILE *fp,*fp2;
    char a[1005],*p;
    int i;

    fp=fopen("E:\\POSN Computer\\Day9\\t.txt","r");
        fscanf(fp," %s",a);
        fclose(fp);

        printf("%s",a);



}

