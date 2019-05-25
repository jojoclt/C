#include<bits/stdc++.h>
using namespace std;
string s;
int x,i,l,cnt;
 
int main(){
    getline(cin,s);
    x = s.length();
    if(x<4) {cout << s << endl; printf("0"); return 0;}
    while(l<=x){
        if((s[l]=='S'||s[l]=='s')&&(s[l+1]=='i' ||s[l+1]=='I')&&(s[l+2]=='p'||s[l+2]=='P')&&(s[l+3]=='a'||s[l+3]=='A')){
             printf("\"");
            for(i=l;i<=l+3;i++){
                printf("%c",s[i]);
            }
             printf("\"");
           l+=4;
            cnt++;
        }
        else {printf("%c",s[l]); l++;}
       
    }
    printf("\n%d",cnt);
}