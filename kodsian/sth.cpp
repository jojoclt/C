#include <bits/stdc++.h>
using namespace std;
int i;
bool decToBinary(int n) 
{ 

    int binaryNum[32];
    int i = 0; 
    while (n > 0) { 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  

    for (int j = i - 1; j >= 0; j--) 
        if (binaryNum[j]) if (binaryNum[j-1]) if (binaryNum[j-2]) return 1;
    return 0;
} 
int main(){
    int cnt = 0;
    for (i = 1; i <= 10000; i++){
        if (decToBinary(i)) ++cnt;
    }
    cout << cnt;
}