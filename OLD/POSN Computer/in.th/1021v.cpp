#include<bits/stdc++.h>
using namespace std;
main(){
    int n,t,i;
    char c;
    scanf("%d",&n);
    vector<int>v;
    vector<int>w;
    for(i=0;i<n;i++){
        cin>>c;
        if(c=='P'){
            scanf("%d",&t);
            v.push_back(t);
            sort(v.begin(),v.end());
        }
        else if(c=='Q'){
            if(!v.empty()){
                t=v.back();
                w.push_back(t);
                v.pop_back();
            }
            else w.push_back(-1);
        }
    }
    for(i=0;i<w.size();i++) {
        std::cout << w.at(i) << '\n';
    }
    return 0;
}
