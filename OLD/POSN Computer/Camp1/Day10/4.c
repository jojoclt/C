#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <string.h>

main(){
int n,i,j,k,l,m,width,height;
    height = 1-1<<31;
    width=0;
    printf("Number of mountains: ");scanf("%d",&n);
    printf("Enter mountains' heights: \n");
    int a[n],h[n],w[n];
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (i=0;i<n;i++){
        if(height<a[i])
            height=a[i];
        width+=2*a[i];
        h[i]=a[i];
        w[i]=2*a[i];
    }
    for (i=0;i<height;i++){
        for (l=0;l<n;l++){
            if(height-h[l]>i)
                for (k=0;k<w[l];k++)
                    printf(" ");
            else{
                    for (k=0;k<height-i-1;k++)
                        printf(" ");
                    printf("/");
                    for (k=0;k<(-height+h[l]+i)*2;k++){
                        printf(" ");
                    }
                    printf("\\");
                    for (k=0;k<height-i-1;k++)
                        printf(" ");
            }

        }
        printf("\n");
    }
    return 0;
}

