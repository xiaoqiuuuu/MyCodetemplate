#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve(){
    int n ;
    cin >> n;
    vector<vector<LL>> g(n + 1 , vector<LL>(n + 1));
    for(int i = 1 ; i <= n ; i ++ ) {
        for(int j = 1 ; j <= i ; j ++ ) {
            cin >> g[i][j];
        }
    }
    
    
    vector<vector<LL>> f(n + 1 , vector<LL>(n + 1));
    for(int i = n ; i >= 1 ; i -- ) {
        for(int j = i ; j >= 1 ; j -- ) {
            if(i == n) {
                f[i][j] = g[i][j];
                continue;
            }
            f[i][j] = max(f[i][j] , f[i + 1][j + 1] + g[i][j]);
            f[i][j] = max(f[i][j] , f[i + 1][j] + g[i][j]);
        }
    }

    cout << f[1][1] << "\n";

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