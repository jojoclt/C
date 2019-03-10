#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int a[100000];
int main(){
	int n,k,i,j,tmp,high = -inf,low = inf,cnt = 0;
	scanf("%d%d",&n,&k);
	for (i = 0; i < n; i++){
		scanf("%d",&tmp);
		a[tmp]++;
		high = max(high,tmp);
		low = min(low,tmp);
	}
	//printf("%d %d",low,high);
	while (high - low > k){
		//printf("\n");
		if (!a[high]){
			//printf("X");
			high--;
		}
		else if (!a[low]){
			//printf("Y");
			low++;
		}
		else{
			if (a[high] == a[low]){
				//printf("a");
				cnt += a[high];
				a[high-1] += a[high],a[high] = 0;
				a[low+1] += a[low],a[low] = 0;
				high--, low++;
			}
			else if (a[high] > a[low]){
				//printf("b");
				cnt+= a[low];
				a[high] -= a[low];
				a[high-1] += a[low];
				a[low+1] += a[low], a[low] = 0;
				low++;
			}
			else if (a[high] < a[low]){
				//printf("c");
				cnt+= a[high];
				a[low] -= a[high];
				a[low+1] += a[high];
				a[high-1] += a[high], a[high] = 0;
				high--;
			}
		}
	}
	printf("%d",cnt);
}
