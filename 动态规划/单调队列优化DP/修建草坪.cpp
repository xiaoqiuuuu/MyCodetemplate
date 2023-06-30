// Problem: 修剪草坪
// Author : Weiqt
// URL: https://www.acwing.com/problem/content/1089/


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve(){
    int n , m;
    cin >> n >> m ;
    vector<int>a(n + 1);
    vector<LL>s(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i], s[i] = s[i - 1] + a[i];
    }
    
    //f[i] 表示从 前 i 头牛中选，合法方案的最大值
    // f[i] = f[i - 1] //不选 
    // f[i] = f[i - 1] + a[i]
    // f[i] = f[i - 2] + a[i] + a[i - 1]
    // f[i] = f[i - 3] + a[i] + a[i - 1] + a[i - 2]
    // f[i] = f[i - k] + s[i] - s[k] 其中 1 >= k && k <= m  
    
    int hh = 0 , tt = 0;
    vector<int>q(n + 1);
    vector<LL>f(n + 1);
    
    auto get = [&](int x) {
        if(!x)return 0ll;
        return f[x - 1] - s[x];
    };
    
    for(int i = 1 ; i <= n ; i ++ ) {
        f[i] = f[i - 1];
        if(tt >= hh && q[hh] < i - m) {
            hh ++ ;
        }
        while(tt >= hh && get(q[tt]) <= get(i)) {
            tt -- ;
        }
        q[++tt] = i;
        f[i] = max(f[i] , get(q[hh]) + s[i]);
    }

    cout << f[n] << "\n";

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