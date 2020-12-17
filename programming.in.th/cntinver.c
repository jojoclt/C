#include <stdio.h>
int a[25];
int n;
int inversion(int a[], int n)
{
    int cnt = 0;
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < j && a[i] > a[j])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", inversion(a, n));
}
