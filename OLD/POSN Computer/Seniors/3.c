#include<stdio.h>
#include<math.h>
/*
4
L U 4
R D 3
L D 6
R U 5
*/
int f(int n){
    if(n==1)return n;
    else if(n==0)return 1;
    else return n*=f(n-1);
}
main(){
    int n,i,j,w;
    scanf("%d",&n);
    char c[n],d[n];
    int h[n];
    for(i=0;i<n;i++){
        scanf(" %c %c %d",&c[i],&d[i],&h[i]);
    }
    int mx=1-1<<31;
    for(i=0;i<n;i++){
        if(h[i]>mx)mx=h[i];
    }
    for(i=0;i<mx;i++){
        for(w=0;w<n;w++){
            for(j=0;j<h[w];j++){
                if(c[w]=='L'){
                    if(d[w]=='U'){
                        if(i<mx-h[w])printf("   ");
                        else{
                            if(j+mx-h[w]<=i)
                                printf("%3d",f(i-mx+h[w])/(f(j)*f(i-mx+h[w]-j)));
                            else printf("   ");
                        }
                    }
                    else if(d[w]=='D'){
                        if(i>h[w])printf("   ");
                        else{
                            if(i+j<h[w])
                                printf("%3d",f(h[w]-i-1)/(f(j)*f(h[w]-i-1-j)));
                            else printf("   ");
                        }
                    }
                    else return 0;
                }
                else if(c[w]=='R'){
                    if(d[w]=='U'){
                        if(i<mx-h[w])printf("   ");
                        else{
                            if(i+j>=h[w])
                                printf("%3d",f(i-mx+h[w])/(f(h[w]-j-1)*f(i-mx+j+1)));
                            else printf("   ");
                        }
                    }
                    else if(d[w]=='D'){
                        if(i>h[j])printf("   ");
                        else{
                            if(j>=i)
                                printf("%3d",f(h[w]-i-1)/(f(h[w]-j-1)*f(j-i)));
                            else printf("   ");
                        }
                    }
                    else return 0;
                }
                else return 0;
            }
        }
        printf("\n");
    }
}
