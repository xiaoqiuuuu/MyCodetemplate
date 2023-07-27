#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve(){
    int n ;
    cin >> n;
    map<int,int> mp;
    
    function<int(int)> next = [&](int x) ->int {
        if(!mp.count(x)) {
            return x;
        } else {
            mp[x] = next(mp[x]);
        }
        return mp[x];    
    };
    
    
    while(n -- ) {
        int x ;
        cin >> x;
        x = next(x);
        cout << x << " ";
        mp[x] = x + 1;
    }
    
    cout << "\n";

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