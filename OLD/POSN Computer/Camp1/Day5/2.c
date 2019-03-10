#include<stdio.h>
main(){
    int n,i,j,k=0;
    scanf("%d",&n);
    int a[n],b[n],c[n];
    for (i=0;i<n;i++){b[i]=0;c[i]=-1;}
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
        for (j=0;j<i;j++){
            if (a[i]==a[j]) {b[j]++;break;}
        }
    }
    j=0;
    for (i=0;i<n;i++)j+=b[i];
    if (b[i]==0)printf("There is no mode");
    else {
            j=-1;
            for (i=0;i<n;i++) if(b[i]>0)b[i]++;
            for (i=0;i<n;i++) if (j<=b[i])j=b[i];
            for (i=0;i<n;i++) if (b[i]==j){c[k]=i;k++;}
            j=0;
            for (i=0;i<n;i++) {
                if (c[i]==-1) j++;
            }
            if (j==n) {j=c[0];printf("The mode is %d",a[j]);}
            else {
                    printf("The modes are ");
                    for (i=0;i<k-1;i++)printf("%d and ",a[c[i]]);
                    printf("%d",a[c[k-1]]);
            }
    }
}

