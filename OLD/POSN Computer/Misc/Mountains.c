#include<stdio.h>
#include<stdlib.h>

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
        width+=2*a[i]-1;
        h[i]=a[i];
        w[i]=2*a[i]-1;
        /*printf("%d = %d x %d\n",a[i],h[i],w[i]);*/
    }
    for (i=0;i<height;i++){
        for (l=0;l<n;l++){
            if(height-i>h[l])
                for (k=0;k<w[l];k++)
                    printf(" ");
            else{
                if(height-h[l]==i){
                    for (k=0;k<a[l]-1;k++)
                        printf(" ");
                    printf("^");
                    for (k=0;k<a[l]-1;k++)
                        printf(" ");
                }
                else{
                    for (k=0;k<a[l]+height-h[l]-i-1;k++)
                        printf(" ");
                    printf("/");
                    for (k=0;k<i-(height-h[l]);k++){
                        printf("%c",'A'+k);
                    }
                    for (k=0;k<i-(height-h[l])-1;k++)
                        printf("%c",'A'+k);
                    printf("\\");
                    for (k=0;k<a[l]+height-h[l]-i-1;k++)
                        printf(" ");
                }
            }

        }
        printf("\n");
    }
    for (k=0;k<width;k++)
                        printf("_");
    return 0;
}
