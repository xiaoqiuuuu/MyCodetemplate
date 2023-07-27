#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve(){
    
    int n ;
    cin >> n;
    vector<int>a(n + 1) , b(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> b[i];
    }
    
    vector<pair<int,int>> ans;
    for(int i = 1 ; i <= n ; i ++ ) {
        int mi = i;
        for(int j = i + 1 ; j <= n ; j ++ ) {
            if(a[j] <= a[mi] && b[j] <= b[mi]) {
                mi = j;
            }
        }
        if(i != mi) {
            ans.push_back({i , mi});
            swap(a[i] , a[mi]);
            swap(b[i] , b[mi]);
        }
    }

    if(is_sorted(a.begin() + 1 , a.end()) && is_sorted(b.begin() + 1 , b.end())) {
        cout << ans.size() << "\n";
        for(auto [l , r] : ans) {
            cout << l << " " << r << "\n";
        }
    } else {
        cout << "-1\n";
    }


    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
    cin >> tt ;
    while(tt --> 0){
        solve();
    }
    
    return 0;
}