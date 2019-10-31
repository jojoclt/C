#include <bits/stdc++.h>
using namespace std;
int i,j;
string cmp[] = {"CAT","RAT","DOG","PIG","COW"},s;

int main(){
    while (1){
        cin >> s;
        int acc = 0;
        for (i = 0; i < 5; i++){
            for (j = 0; j < 3; j++){
                acc += abs(cmp[i][j]-s[j]);
            }
        }
        cout << s << " = " << acc<<endl;
    }
}