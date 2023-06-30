// Problem: C. Watching Fireworks is Fun
// Author : Weiqt
// URL: https://codeforces.com/contest/372/problem/C


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct Node{
    LL a , b , t;
};

void solve(){
    int n , m , d;
    cin >> n >> m >> d;
    vector<Node>v(m + 1);
    for(int i = 1 ; i <= m ; i ++ ) {
        auto &[a , b , t]  = v[i];
        cin >> a >> b >> t;
    }
    
    int tt = - 1 , hh = 0;
    vector<int>q(n + 1);
    vector<LL>g(n + 1);
    vector<LL>f(n + 1);
    // f[i][j] 表示第 i 个位置看完了 前 j 个花的最大价
    v[0].t = -1e9;
    for(int j = 1 ; j <= m ; j ++ ) {
        tt = -1 , hh = 0;
        auto [a , b , t] = v[j];
        t = v[j].t - v[j - 1].t;
        for(int i = 1 ; i <= n ; i ++ ) {
            if(tt >= hh && q[hh] < i - t * d ) {
                hh ++  ;
            }
            while(tt >= hh && g[q[tt]] <= g[i]) {
                tt -- ;
            }
            q[++tt] = i;
            f[i] = g[q[hh]] + b - abs(a - i);
        }
       tt = - 1 , hh = 0;
       for(int i = n ; i >= 1 ; i -- ) {
           if(tt >= hh && q[hh] > i + t * d) {
               hh ++ ;
           }
           while(tt >= hh && g[q[tt]] <= g[i]) {
               tt -- ;
           }
            q[++tt] = i;
            f[i] = max(g[q[hh]] + b - abs(a - i) , f[i]);
           
       }
       swap(f , g);
    }

    LL mi = -1e18;
    for(int i = 1 ; i <= n ; i ++ ) {
        mi = max(mi , g[i]);
    }
    
    cout << mi << "\n";
// 
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