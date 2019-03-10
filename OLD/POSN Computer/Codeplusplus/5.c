#include<string.h>
int main(){
    char x[1005],y[1005];
    int i,j;
    scanf("%s %s",x,y);
    for(i=0;i<strlen(x);i++){
        for(j=0;j<strlen(y);j++){
            if(x[i]=='O'){
                i++;
                if(x[i]=='+'){
                    j++;
                    if(y[j]=='B')j++;
                    if(y[j]=='+'){
                        printf("Compatible");
                        break;
                    }
                }
                else if(x[i]=='-'){
                    printf("Compatible");
                    break;
                }
            }
            else if(x[i]=='A'){
                if(x[i+1]=='B'){
                    i+=2;
                    if(x[i]=='+'){
                        if(strcmp(y,"AB+")==0){
                            printf("Compatible");
                            break;
                        }
                    }
                    else if(x[i]=='-'){
                        if(y[0]=='A'&&y[1]=='B'){
                            printf("Compatible");
                            break;
                        }
                    }
                }
                else{
                    i++;
                    if(x[i]=='+'){
                        if(y[j]=='A'){
                            j++;
                            if(y[j]=='+'){
                                printf("Compatible");
                                break;
                            }
                            else if(y[j]=='B'){
                                j++;
                                if(y[j]=='+'){
                                    printf("Compatible");
                                    break;
                                }
                            }
                        }
                    }
                    else if(x[i]=='-'){
                        if(y[j]=='A'){
                            printf("Compatible");
                            break;
                        }
                    }
                }
            }
            else if(x[i]=='B'){
                i++;
                if(x[i]=='+'){
                    if(y[j]=='B'){
                        j++;
                        if(y[j]='+'){
                            printf("Compatible");
                            break;
                        }
                        else printf("Incompatible");
                    }
                }
                else if(x[i]=='-'){
                    if(y[j]=='B'){
                        printf("Compatible");
                        break;
                    }
                }
            }
        }
    }
    if(strlen(y)==j)printf("Incompatible");
    return 0;
}
