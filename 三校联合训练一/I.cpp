#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve(){
    int n ;
    cin >> n;
    
    
    vector<pair<int,int>> ans ;
    
    for(int i = 1 ; i <= n / 2; i ++ ) {
        int k ;
        if(n % i == 0) {
            k = n / i;
            if(k % 2 == 0) {
                continue;
            }
            k /= 2;
            if(i > k) {
                ans.push_back({i - k , i + k});
            }
            
        } 
        if(n % (2 * i + 1) == 0) {
            k = n / (2 * i + 1);
            if(i >= k) {
               ans.push_back({i - k + 1 , i + k });
            }
        }   
    }

    sort(ans.begin() , ans.end());
    for(auto [l , r] : ans) {
        cout << l << " " << r << "\n";
    }


    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
   // cin >> tt ;
    while(tt --> 0){
        solve();
    }
    
    return 0;
}