#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
main(){
    struct student{
        int id;

        char name[20];
        float score;
    }std[10];
    std[0].id=101;
    std[1].id=201;
    std[2].id=105;
    std[3].id=315;
    std[4].id=323;
    std[5].id=107;
    std[6].id=209;
    std[7].id=106;
    std[8].id=210;
    std[9].id=327;
    strcpy(std[0].name,"anucha");
    strcpy(std[1].name,"bow");
    strcpy(std[2].name,"ananda");
    strcpy(std[3].name,"aran");
    strcpy(std[4].name,"boonchai");
    strcpy(std[5].name,"bewilai");
    strcpy(std[6].name,"bori");
    strcpy(std[7].name,"aunya");
    strcpy(std[8].name,"aroon");
    strcpy(std[9].name,"beraphat");
    std[0].score=78.50;
    std[1].score=71.00;
    std[2].score=60.00;
    std[3].score=74.00;
    std[4].score=90.75;
    std[5].score=58.50;
    std[6].score=55.00;
    std[7].score=40.50;
    std[8].score=68.25;
    std[9].score=95.00;
    char s[5];
    int i,j,k=0;
    scanf(" %s",s);
    if(strcmp(s,"id")==0){
        int n;
        scanf("%d",&n);
        if(n>=0&&n<10){
            for(i=0;i<10;i++){
                if(std[i].id-n*100>=0&&std[i].id-n*100<100)
                    printf("%d %s %.2f\n",std[i].id,std[i].name,std[i].score);
            }
        }
        else if(n<100){
            for(i=0;i<10;i++){
                if(std[i].id-n*10>=0&&std[i].id-n*10<10)
                    printf("%d %s %.2f\n",std[i].id,std[i].name,std[i].score);
            }
        }
        else if(n<1000){
            for(i=0;i<10;i++){
                if(n==std[i].id)
                    printf("%d %s %.2f\n",std[i].id,std[i].name,std[i].score);
            }
        }
        else printf("none");
    }
    else if(strcmp(s,"name")==0){
        char n[8];
        scanf(" %s",n);
        for(j=0;j<10;j++){
            for(i=0;i<strlen(n);i++){
                if(n[i]!=std[j].name[i])
                    break;
                else continue;
            }
            if(i==strlen(n)){
                printf("%d %s %.2f\n",std[j].id,std[j].name,std[j].score);
                k++;
            }
        }
        if(k==0)printf("none");
    }
    else if(strcmp(s,"score")==0){
        char n[5];
        scanf(" %s",n);
        if(strlen(n)==1){
            for(i=0;i<10;i++){
                if(std[i].score-atof(n)*10>=0&&std[i].score-atof(n)*10<10){
                    printf("%d %s %.2f\n",std[i].id,std[i].name,std[i].score);
                    k++;
                }
            }
            if(k==0)printf("none");
        }
        else if(strlen(n)==2){
            for(i=0;i<10;i++){
                if(std[i].score-atof(n)>=0&&std[i].score-atof(n)<1){
                    printf("%d %s %.2f\n",std[i].id,std[i].name,std[i].score);
                    k++;
                }
            }
            if(k==0)printf("none");
        }
        else if(strlen(n)==3){
            if(n[2]!='.')printf("none");
            else{
                for(i=0;i<10;i++){
                    if(std[i].score-atof(n)>=0&&std[i].score-atof(n)<1){
                        printf("%d %s %.2f\n",std[i].id,std[i].name,std[i].score);
                        k++;
                    }
                }
                if(k==0)printf("none");
            }
        }
        else if(strlen(n)==4){
            for(i=0;i<10;i++){
                if(std[i].score-atof(n)>=0&&std[i].score-atof(n)<0.1){
                    printf("%d %s %.2f\n",std[i].id,std[i].name,std[i].score);
                    k++;
                }
            }
            if(k==0)printf("none");
        }
        else if(strlen(n)==5){
            for(i=0;i<10;i++){
                if(std[i].score==atof(n)){
                    printf("%d %s %.2f\n",std[i].id,std[i].name,std[i].score);
                    k++;
                }
            }
            if(k==0)printf("none");
        }
        else printf("none");
    }
    return 0;
}
