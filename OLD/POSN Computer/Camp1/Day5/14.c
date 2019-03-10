#include<stdio.h>
#include<stdlib.h>

main(){
    char t1[1005],t2[1005],t3[1005],t4[1005];
    printf("Text1: ");scanf ("%[^\n]%*c", t1);
    printf("Text2: ");scanf ("%[^\n]%*c", t2);
    printf("Text3: ");scanf ("%[^\n]%*c", t3);
    printf("Text4: ");scanf ("%[^\n]%*c", t4);
    printf("%s: %d\n",t1,strlen(t1));
    printf("%s: %d\n",t2,strlen(t2));
    printf("%s: %d\n",t3,strlen(t3));
    printf("%s: %d\n",t4,strlen(t4));

}
