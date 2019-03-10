#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
    char a[1005];
    int i,j,k;
    scanf(" %s",a);
    for(i=0;i<strlen(a);i++){
        if(a[i]<'0'||a[i]>'9'){
            printf("error");
            return 0;
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<strlen(a);j++){
            for(k=0;k<5;k++){
                if(i==0){
                    if(k==0){
                        if(a[j]=='1')printf(" ");
                        else printf("*");
                    }
                    else if(k>0&&k<4){
                        if(a[j]=='1'||a[j]=='4')printf(" ");
                        else printf("*");
                    }
                    else if(k==4){
                        printf("*");
                    }
                }
                else if(i==1){
                    if(k==0){
                        if(a[j]=='1'||a[j]=='2'||a[j]=='3'||a[j]=='7')printf(" ");
                        else printf("*");
                    }
                    else if(k>0&&k<4){
                        printf(" ");
                    }
                    else if(k==4){
                        if(a[j]=='5'||a[j]=='6')printf(" ");
                        else printf("*");
                    }
                }
                else if(i==2){
                    if(k==0){
                        if(a[j]=='1'||a[j]=='7')printf(" ");
                        else printf("*");
                    }
                    else if(k>0&&k<4){
                        if(a[j]=='1'||a[j]=='7'||a[j]=='0')printf(" ");
                        else printf("*");
                    }
                    else if(k==4){
                        printf("*");
                    }
                }
                else if(i==3){
                    if(k==0){
                        if(a[j]=='6'||a[j]=='2'||a[j]=='8'||a[j]=='0')printf("*");
                        else printf(" ");
                    }
                    else if(k>0&&k<4){
                        printf(" ");
                    }
                    else if(k==4){
                        if(a[j]=='2')printf(" ");
                        else printf("*");
                    }
                }
                else if(i==4){
                    if(k>=0&&k<4){
                        if(a[j]=='1'||a[j]=='7'||a[j]=='4'||a[j]=='9')printf(" ");
                        else printf("*");
                    }
                    else if(k==4){
                        printf("*");
                    }
                }
            }
    printf(" ");
        }
        printf("\n");
    }
}

