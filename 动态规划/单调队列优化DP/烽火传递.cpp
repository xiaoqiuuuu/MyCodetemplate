// Problem: 
//     T159083 烽火传递
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/T159083


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve(){
    int n , m;
    cin >> n >> m;
    vector<int>a(n + 1) , f(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        cin >> a[i];
    }
    
    f[0] = 0;
    //f[i] 表示前i个烽火台 ，保证通信且第 i个是烽火台的最小价值
    int tt = - 1 , hh = 0;
    vector<int>q(n + 1);
    for(int i = 1 ; i <= n ; i ++ ) {
        if(hh <= tt && q[hh] < i - m) {
             hh ++ ;
        }
        while(hh <= tt && f[q[tt]] >= f[i - 1]) {
            tt -- ;
        }
        q[++tt] = i - 1;
        f[i] = f[q[hh]] + a[i];
    }
    
    cout << *min_element(f.end() - m , f.end()) << "\n";
    
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