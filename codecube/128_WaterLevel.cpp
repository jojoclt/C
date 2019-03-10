#include <bits/stdc++.h>
using namespace std;

int n,a[1000005],maxx,pos;
int i,j;
int main(){
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	i = 1;
	while (i < n){
        if (a[i] <= a[i+1]){
            printf("%d ",a[i++]);
        }
        else if (a[i] > a[i+1]){
            for (j = i+1; j <= n; j++){
                if (maxx < a[j] && maxx <= a[i]){
                    maxx = a[j];
                    pos = j;
                }
                if (maxx > a[i]){
                    maxx = a[i];
                    break;
                }
            }
//            printf("pos=%d\n",pos);
            for ( ; i < pos; i++){
                printf("%d ",maxx);
            }
            maxx = 0;
        }
	}
}
