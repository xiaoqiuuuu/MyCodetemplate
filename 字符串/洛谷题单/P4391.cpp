// Problem: 
//     P4391 [BOI2009] Radio Transmission 无线传输
//   
// Author : Weiqt
// URL: https://www.luogu.com.cn/problem/P4391


#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve(){
    int n ;
    string s;
    cin >> n >> s ;
    s = " " + s ;

    vector<int> ne(n + 1);
    for(int i = 2 , j = 0; i <= n ; i ++ ) {
        while(j && s[j + 1] != s[i]) {
            j = ne[j];
        }
        if(s[j + 1] == s[i]) {
            j ++ ;
        }
        ne[i] = j;
    }
    cout << n - ne[n] << "\n";

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