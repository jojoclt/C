#include<bits/stdc++.h>
using namespace std;
int n;
char str[6]="12345";
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int l)
{
   int i;
   if (l == n-1)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= n-1; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1);
          swap((a+l), (a+i));
       }
   }
}

int main()
{
    n = strlen(str);
    permute(str, 0);
    return 0;
}
