// Problem: 最大子序和
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/description/137/


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve(){
    int n , m;
    cin >> n >> m ;
    vector<int>a(n + 1) ,s(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i] , s[i] = s[i - 1] + a[i];
    }
    
    int hh = 0 , tt = -1;
    vector<int>q(n + 1);int ans = -0x3f3f3f3f;
    for(int i = 1 ; i <= n ; i ++  ) {
        if(tt >= hh && q[hh] < i - m + 1) {
            hh ++ ;
        }
        while(tt >= hh && s[q[tt]] >= s[i]) { 
            tt -- ;
        }
        q[++tt] = i  ;
        ans = max(ans , s[i] - s[q[hh] - 1]);
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