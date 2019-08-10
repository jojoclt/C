#include <bits/stdc++.h>
using namespace std;
int n,i,j,t;
int status = 0;
string s;
int main(){
    scanf("%d",&n);
    for (i = 1; i <= n; i++){
        status = 0;
        cin >> s;
        t = s.length();
        for (j = 0; j < t; j++){
            if (s[j] == 'X') status = max(status,3);
            if (s[j] == 'T') status = max(status,2);
            if (s[j] == '-') status = max(status,1);
        }
        printf("Case #%d: ",i);
        switch (status){
            case 3: cout << "No - Runtime error\n";
                    break;
            case 2: cout << "No - Time limit exceeded\n";
                    break;
            case 1: cout << "No - Wrong answer\n";
                    break;
            default: cout<< "Yes\n";

        }
    }
}