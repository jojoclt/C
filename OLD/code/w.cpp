#include <bits/stdc++.h>
using namespace std;

int main(){

string a = "03/02";
map <string,int>m;
swap(a[1],a[4]);
m[a] = 2;
cout << m[a];
}
