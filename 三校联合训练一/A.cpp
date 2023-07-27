#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 160;

char g[N][N];

void solve(){
     int n ;
     cin >> n;

    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> (g[i] + 1);  
    }    
    
    vector<vector<int>> s(n + 1 , vector<int>( n + 1));
    
    for(int i = 1 ; i <= n ; i ++ ) {
        for(int j = 1 ; j <= n ; j ++ ) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (g[i][j] == 'W');
        }
    }
    
    int ans = 0 ;
    for(int x1 = 1 ; x1 <= n ; x1 ++ ) {
        for(int y1 = 1 ; y1 <= n ; y1 ++ ) {
            for(int x2 = x1 ; x2 <= n ; x2 ++ ) {
                for(int y2 = y1 ; y2 <= n ; y2 ++ ) {
                    if(s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 -1] + s[x1 - 1][y1 - 1] == (y2 - y1 + 1) * (x2 - x1 + 1)) {
                        ans ++ ;
                    }
                }
            }
        }
    }
    
    cout << ans << "\n";

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