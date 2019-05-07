#include <iostream>
using namespace std;
int n;
int main() {
	
	while (scanf("%d",&n),n){
		printf("%d\n",n*(n+1)*(2*n+1)/6);
	}
	return 0;
}