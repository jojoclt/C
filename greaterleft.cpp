#include <bits/stdc++.h>
using namespace std;
int q,i,n,t,cnt;
vector <int> a;
void insertionSort(std::vector<int> &vec) 
{ 
    for (auto it = vec.begin(); it != vec.end(); it++) 
    {         
        // Searching the upper bound, i.e., first  
        // element greater than *it from beginning 
        auto const insertion_point =  
                std::upper_bound(vec.begin(), it, *it); 
          
        // Shifting the unsorted part 
        std::rotate(insertion_point, it, it+1);         
    } 
} 
int main(){
    ios::sync_with_stdio(0);
    cin >> q;
    while (q--){
        a.clear()
        cin >> n;
        for (i = 0; i < n; i++){
            cnt = 0;
            cin >> a[i];
            insertionSort(a);
            
        }
    }
}