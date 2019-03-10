#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[10],i,sum=0,*p;
int comparetor (const void * a, const void * b)
	{
		return ( *(int*)a - *(int*)b );
	}
main(){
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    qsort (a, 10, sizeof(int), comparetor);
    p=a;
    for (i=0; i<10; i++)
        printf ("%d ",*(p++));
    return 0;
}

